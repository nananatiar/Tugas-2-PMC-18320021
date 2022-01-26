//Program Round Robin
//Program mencari waktu proses, yakni waktu dimana proses selesai dijalankan dikurangi waktu proses datang
//Program mencari waktu tunggu, yakni waktu sampai proses sampai di antrian
//Program mencari rata-rata waktu proses dan waktu tunggu dari semua proses
#include<stdio.h>
 
int main()
{
 
  int count,j,n,time,remain,flag=0,waktu_kuantum;
  int waktu_tunggu=0,waktu_proses=0,at[10],bt[10],rt[10]; //at : waktu kedatangan, bt : waktu eksekusi
  printf("Masukkan Total Proses :\t ");
  scanf("%d",&n);
  remain=n;
  for(count=0;count<n;count++)
  {
    printf("Masukkan Waktu Kedatangan Proses %d :",count+1);
    scanf("%d",&at[count]);
    printf("Masukkan Waktu Eksekusi Proses %d :",count+1);
    scanf("%d",&bt[count]);
    rt[count]=bt[count];
  }
  printf("Masukkan Kuantum:\t");
  scanf("%d",&waktu_kuantum);
  printf("\n\nProses\t| Waktu Proses\t| Waktu Tunggu\n\n");
  for(time=0,count=0;remain!=0;)
  {
    if(rt[count]<=waktu_kuantum && rt[count]>0)
    {
      time+=rt[count];
      rt[count]=0;
      flag=1;
    }
    else if(rt[count]>0)
    {
      rt[count]-=waktu_kuantum;
      time+=waktu_kuantum;
    }
    if(rt[count]==0 && flag==1)
    {
      remain--;
      printf("P[%d]\t|\t%d\t|\t%d\n",count+1,time-at[count],time-at[count]-bt[count]);
      waktu_tunggu+=time-at[count]-bt[count]; //Mencari waktu tunggu
      waktu_proses+=time-at[count]; //Mencari waktu proses
      flag=0;
    }
    if(count==n-1)
      count=0;
    else if(at[count+1]<=time)
      count++;
    else
      count=0;
  }
  printf("\nRata-Rata Waktu Tunggu = %f\n",waktu_tunggu*1.0/n);
  printf("Rata-Rata Waktu Proses = %f",waktu_proses*1.0/n);
  
  return 0;
}