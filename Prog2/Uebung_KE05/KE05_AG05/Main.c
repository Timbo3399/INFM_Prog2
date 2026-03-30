#include <stdio.h>
#define ARRAY_LEN (5)

struct Bar
{
	char acBarName[30];
	char acSpecialOffer[30];
	char acTown[20];
};


int main(void)
{
	struct Bar a_bar[ARRAY_LEN] = 
	{
		{"Test1","Bier","Offenburg" },
		{"Test2", "Bir", "Memmingen"},
		{"Test3","ImmerBier","Aitrach"},
		{"Test4","BierFourEvar","Appenweier"},
		{"Test5","AlwaysBier","Urloffen"}
	};


	for (int i = 0; i < ARRAY_LEN; i++)
	{
		printf("acBarName: %s acSpecialOffer: %s acTown: %s\n",a_bar[i].acBarName, a_bar[i].acSpecialOffer, a_bar[i].acTown);
	}
}