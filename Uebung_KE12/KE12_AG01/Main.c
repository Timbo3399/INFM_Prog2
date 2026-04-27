#include <stdio.h>
#include <stdlib.h>
#include <stdint.h>
#include <math.h>
#include <windows.h>

// Module-specific types
typedef struct sThreadParams_t
{
   int iStart;
   int iEnd;
} sThreadParams_t;

// Global array as required by the task
double adArray[10000];

// Function declarations (all except main)
DWORD WINAPI Thread_InitRange(LPVOID pvParam);

// Function implementations
int main(void)
{
   // Local variables
   LARGE_INTEGER liFreq;
   LARGE_INTEGER liStart;
   LARGE_INTEGER liEnd;
   double dElapsedMs;
   HANDLE hThread;
   DWORD dwThreadId;
   sThreadParams_t sParam;
   HANDLE ahThreads[4];
   sThreadParams_t asParams[4];
   int i;

   // Query performance frequency
   QueryPerformanceFrequency(&liFreq);

   // ----- Single-threaded run -----
   sParam.iStart = 0;
   sParam.iEnd = 9999;

   QueryPerformanceCounter(&liStart);

   hThread = CreateThread(
      NULL,
      0,
      Thread_InitRange,
      &sParam,
      0,
      &dwThreadId);

   if (hThread == NULL)
   {
      printf("Failed to create thread (single-threaded run).\n");
      return 1;
   }

   // Wait for the single thread to finish
   WaitForSingleObject(hThread, INFINITE);
   CloseHandle(hThread);

   QueryPerformanceCounter(&liEnd);
   dElapsedMs = (double)(liEnd.QuadPart - liStart.QuadPart) * 1000.0 / (double)liFreq.QuadPart;
   printf("Single-threaded initialization time: %.3f ms\n", dElapsedMs);

   // ----- Multi-threaded run (4 threads) -----
   // Reset array to zero (optional, for fair measurement)
   for (i = 0; i < 10000; i = i + 1)
   {
      adArray[i] = 0.0;
   }

   // Prepare 4 parameter blocks (inclusive end indices)
   asParams[0].iStart = 0;
   asParams[0].iEnd = 2499;
   asParams[1].iStart = 2500;
   asParams[1].iEnd = 4999;
   asParams[2].iStart = 5000;
   asParams[2].iEnd = 7499;
   asParams[3].iStart = 7500;
   asParams[3].iEnd = 9999;

   QueryPerformanceCounter(&liStart);

   for (i = 0; i < 4; i = i + 1)
   {
      ahThreads[i] = CreateThread(
         NULL,
         0,
         Thread_InitRange,
         &asParams[i],
         0,
         NULL);

      if (ahThreads[i] == NULL)
      {
         printf("Failed to create thread %d (multi-threaded run).\n", i);
         // Close any created handles and exit
         for (int j = 0; j < i; j = j + 1)
         {
            CloseHandle(ahThreads[j]);
         }
         return 1;
      }
   }

   // Wait for all 4 threads
   WaitForMultipleObjects(4, ahThreads, TRUE, INFINITE);

   for (i = 0; i < 4; i = i + 1)
   {
      CloseHandle(ahThreads[i]);
   }

   QueryPerformanceCounter(&liEnd);
   dElapsedMs = (double)(liEnd.QuadPart - liStart.QuadPart) * 1000.0 / (double)liFreq.QuadPart;
   printf("4-threaded initialization time: %.3f ms\n", dElapsedMs);

   // Optional: verify few values
   printf("adArray[0] = %.6f\n", adArray[0]);
   printf("adArray[9999] = %.6f\n", adArray[9999]);

   return 0;
}

DWORD WINAPI Thread_InitRange(LPVOID pvParam)
{
   sThreadParams_t* psParams;
   int iIndex;

   if (pvParam == NULL)
   {
      return 1;
   }

   psParams = (sThreadParams_t*)pvParam;

   for (iIndex = psParams->iStart; iIndex <= psParams->iEnd; iIndex = iIndex + 1)
   {
      adArray[iIndex] = sqrt((double)iIndex);
   }

   return 0;
}
