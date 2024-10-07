#include <pthread.h>
#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>

void* csu(void *data){

    int i=*((int*)data);
    if(i%2==0&&i%5!=0)
        printf("CSU ");
    return NULL;
}
void* sb(void *data){
    int i=*((int*)data);
    if(i%5==0&&i%2!=0)
        printf("SB ");
    return NULL;
}
void* csusb(void *data){
    int i=*((int *)data);
    if(i%2==0&&i%5==0)
        printf("CSUSB ");
    return NULL;
}
void* number(void *data){
    int i=*((int *)data);
    if(i%2!=0&&i%5!=0)
        printf("%d ",i);
    return NULL;
}
int main(){
    //int thr_id;
    pthread_t p_thread[4];

    for(int i=1;i<=50;i++){
        pthread_create(&p_thread[0],NULL,&csu,(void*)&i);
        pthread_create(&p_thread[1],NULL,&sb,(void*)&i);
        pthread_create(&p_thread[2],NULL,&csusb,(void*)&i);
        pthread_create(&p_thread[3],NULL,&number,(void*)&i);
        sleep(0);
    }

    for(int i=0;i<4;i++){
        pthread_join(p_thread[i],NULL);
    }
    return 0;
}
