#include <stdio.h>
#include <stdlib.h>
#include <sys/types.h>
#include <stdbool.h>


 int NoPrcoss;
 int NoResctype;


int main(){

   printf("%s "," Enter No of Processes : ");
   scanf("%d",&NoPrcoss);

   printf("%s"," Enter No of Resource types : ");
   scanf("%d",&NoResctype);

   int Available[NoResctype];
   int Allocation[NoPrcoss][NoResctype];
   int Max[NoPrcoss][NoResctype];
   int Need[NoPrcoss][NoResctype];

   int ProcessExcuteOrder[NoPrcoss];


   int Work[NoResctype];
   bool Finished[NoPrcoss];

   // Reading_Txt
   FILE *infile1,*infile2,*infile3;

       infile1 = fopen("Available.txt", "r");
       infile2 = fopen("Max.txt", "r");
       infile3 = fopen("Allocation.txt", "r");

   if(infile1 == NULL || infile2 == NULL || infile3 == NULL)
   {
       printf("Error opening file\n");
       exit(1);
   }

   for(int i=0;i<NoPrcoss;i++){

      for(int j=0;j<NoResctype;j++){

          fscanf(infile2,"%d",&Max[i][j]);
          fscanf(infile3,"%d",&Allocation[i][j]);

      }

   }

   for(int j=0;j<NoResctype;j++){

       fscanf(infile1,"%d,",&Available[j]);

   }



       fclose(infile1);
       fclose(infile2);
       fclose(infile3);

// Printing Available Max , and  Allocation
printf("%s\n","## Available ## ");
for(int i=0;i<NoResctype;i++){

  printf(" %d ",Available[i]);


}
printf("\n %s \n","---------------------------------------------------------------");


printf("%s \t %s  \t %s\n","Maximum","Allacation"," Need");

for(int i=0;i<NoPrcoss;i++){

   for(int j=0;j<NoResctype;j++){

       printf("%d ",Max[i][j]);
   }

    printf("\t \t   ");
   for(int j=0;j<NoResctype;j++){
       printf("%d ",Allocation[i][j]);
   }

   printf("\t  ");

   //Calculating Need and Printing
  for(int j=0;j<NoResctype;j++){
      printf("%d ",(Need[i][j]=Max[i][j] - Allocation[i][j]) );
  }

   printf("\n");

}


//Initial State
for(int i=0;i<NoResctype;i++){
   Work[i]=Available[i];
}
// Printing Available Max , and  Allocation
printf("\n %s\n","-------------------------------------------");
printf("%s\n","## Work ## ");
for(int i=0;i<NoResctype;i++){

  printf(" %d ",Work[i]);

}
printf("\n %s\n","-------------------------------------------");



Safety_State_Algo:for(int j=0;j<NoPrcoss;j++){

    Finished[j]=false;
}



//Safe state Algorithem

bool SafeState=true;

int FinishProcesCount=0;


while(FinishProcesCount<NoPrcoss){

int  State=0;


for(int i=0;i<NoPrcoss;i++){

   if(Finished[i]==false){

           int RescStateCnt=0;

           for(int j=0;j<NoResctype;j++){


                 if(  (Need[i][j] <= Work[j] )  ){
                          RescStateCnt++;
                 }

          }

             if(RescStateCnt==NoResctype){

                  for(int j=0;j<NoResctype;j++){

                      Work[j]=Work[j]+Allocation[i][j];
                      State=1;

                 }

                 Finished[i]=true;
                 ProcessExcuteOrder[FinishProcesCount]=i;

                 FinishProcesCount++;

          }

   }else{
       FinishProcesCount++;
   }


  }


if(State==0){ // Stopping Critia
  SafeState=false;
  break;
}


}


 if (SafeState) {
    printf("%s\n","-----------------------------------------------------");
    printf("%s\n","System is in Safe State ");
    printf("\n %s \n","-----------------------------------------------------");
    printf("%s\n"," Optimized Order of Process Execution :");
    for(int id=0;id<NoPrcoss;id++){

      printf(" %d %s[%d] \n",(id+1) ,".Process id :",ProcessExcuteOrder[id] );
    }
    printf("\n %s \n","-----------------------------------------------------");

//Resource-Request Algorithm
    int ProsNo;
    printf("%s "," Enter No of Process : ");
    scanf("%d",&ProsNo);

    ProsNo=ProsNo-1;

    int RequestPrcs[NoResctype];

    printf("%s"," Enter Request Resources : ");
    for (int k=0;k<NoResctype;k++) {
       scanf("%d",&RequestPrcs[k]);
    }
    printf("\n %s\n","---------------------------------------------------");
    printf("%s\n","Request Resources");
    for (int k=0;k<NoResctype;k++) {
       printf("%d ", RequestPrcs[k]);
    }
  printf("\n%s\n","----------------------------------------");


  int ReSCount=0;

  for (int y=0;y<NoResctype;y++) {

       if( RequestPrcs[y] <= Need[ProsNo][y] ){
              ReSCount++;
       }

  }

   if(ReSCount==NoResctype){


     int ReSAllvCount=0;

     for (int z=0;z<NoResctype;z++) {

          if( RequestPrcs[z] <= Available[z] ){
                 ReSAllvCount++;
          }

     }

        if(ReSAllvCount==NoResctype){

            for (int iR=0;iR<NoResctype;iR++) {

                Available[iR]=Available[iR]-RequestPrcs[iR];
                Allocation[ProsNo][iR]=Allocation[ProsNo][iR]+RequestPrcs[iR];
                Need[ProsNo][iR]=Need[ProsNo][iR]-RequestPrcs[iR];

            }

           printf("%s\n"," Request Granted ");

            goto Safety_State_Algo;
            FinishProcesCount=0;


        }else{

          printf("\n %s  %d %s \n","Wait Process [",ProsNo,"] until resources are available");

        }


   }else{

     printf("%s\n"," Error : Request cannt grant ");

   }



 }else{
    printf("%s\n","-----------------------------------------------------");
    printf("%s\n","System is not in Safe  State");
    printf("%s\n","-----------------------------------------------------");
 }





  return 0;


}
