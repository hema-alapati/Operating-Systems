#include <stdio.h>
//21BPS1384
//Alapati Hemalatha
int main(){
   int n,m;
   printf("Enter the number of processes and resources: ");
   scanf("%d %d",&m,&n);
   int allocated[m][n];
   int max[m][n];
   int need[m][n];
   for(int i=0;i<m;i++){
        printf("Enter the allocated resource of process p%d: ",i);
        for(int j=0;j<n;j++){
            scanf("%d",&allocated[i][j]);
        }
    } 
   for(int i=0;i<m;i++){
        printf("Enter the max no of resources needed by process p%d: ",i);
        for(int j=0;j<n;j++){
            scanf("%d",&max[i][j]);
        }
    }
    for(int i=0;i<m;i++){
        for(int j=0;j<n;j++){
            need[i][j]=max[i][j]-allocated[i][j];
        }
    }
    printf("The need matrix is:\n");
    for(int i=0;i<m;i++){
        for(int j=0;j<n;j++){
            printf("%d ",need[i][j]);
        }
        printf("\n");
    }
    int available[m][n];
    for(int i=0;i<m;i++){
        for(int j=0;j<n;j++){
            available[i][j]=0;
        }
    }
    printf("Enter the available resources: ");
    for(int i=0;i<n;i++){
        scanf("%d",&available[0][n]);
    }
    int flag[m];
    for(int i=0;i<m;i++){
        flag[i]=0;
    }
    for(int i=0;i<m;i++){
        for(int j=0;j<n;j++){
            if((flag[i]==0)&&(need[i][j])<=available[i][j]){
                flag[i]=1;
                available[i][j]+=allocated[i][j];
            }
        }
    }
    int temp=0;
    for(int i=0;i<m;i++){
        if(flag[i]==1){
            continue;
        }
        else{
            break;
        }
        temp=1;
    }
    if(temp==0){
        printf("It's in safe state");
    }
    else{
        printf("It is not in safe state");
    }
}