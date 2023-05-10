#include<stdio.h>
#include <time.h>
void DoiCho(int &a, int &b){
    int temp=a;
    a=b;
    b=temp;
}

int Weight = 0;
int Value = 0;
//Khoi luong tang dan
void KL_up(int a[][2], int n) {
    int i, j, min_idx;

    for (i = 0; i < n-1; i++) {
        min_idx = i;
        for (j = i+1; j < n; j++) {
            if (a[j][0] < a[min_idx][0])
                min_idx = j;
        }
        // swap the minimum element with the current element
        DoiCho(a[i][0],a[min_idx][0]);
        DoiCho(a[i][1],a[min_idx][1]);
    }
}
 //sap xep theo gia tri giam dan
void GiaTri_down(int a[][2], int n){
	int i, j, max_idx;
	
    for (i = 0; i < n-1; i++) {
        max_idx = i;
        for (j = i+1; j < n; j++) {
            if (a[j][1] > a[max_idx][1])
                max_idx = j;
        }
        // swap the minimum element with the current element
        DoiCho(a[i][0],a[max_idx][0]);
        DoiCho(a[i][1],a[max_idx][1]);
    }
}
//sap xep theo ty suat gia/trongluong giam dan
void TySuat(int a[][2], int n){
	int i, j, max_idx;
	
    for (i = 0; i < n-1; i++) {
        max_idx = i;
        for (j = i+1; j < n; j++) {
            if ((a[j][1]/a[j][0]) > (a[max_idx][1]/a[max_idx][0]))
                max_idx = j;
        }
        // swap the minimum element with the current element
        DoiCho(a[i][0],a[max_idx][0]);
        DoiCho(a[i][1],a[max_idx][1]);
    }
}
void knapsack(int W,int a[][2], int n,int index){     //index la chi so cua phan tu co khoi luong nang nhat con lai
    if(a[index][0]>W)    return;
    else{
        Weight += a[index][0];
        Value += a[index][1];
        printf("%d    %d\n",a[index][0],a[index][1]);
        W = W - a[index][0];
        index++;
        knapsack(W,a,n,index);
    }          
}
int main(){
    int a[80][2];
    int n = 40, v, w;
    FILE *f = fopen("CaiTui3.txt", "r");

    if (f == NULL) {
        printf("Khong mo duoc file\n");
        return 0;
    }

    for(int i=0; i<n; i++){
        if (fscanf(f, "%d %d", &w, &v) != 2) {
            printf("Loi khi doc file\n");
            return 0;
        }
        a[i][0]=w;
        a[i][1]=v;
    }
    fclose(f);

    printf("Nhap khoi luong toi da:");
    scanf("%d",&w);
    clock_t start = clock();
    KL_up(a, n);
   	//GiaTri_down(a,n);
    //TySuat(a,n);
    knapsack(w,a,n,0);
    clock_t end = clock();
    double duration = double(end - start) / CLOCKS_PER_SEC;
    printf("Thoi gian chay: %d", duration);
    printf("\nGia tri do vat: %d",Value);
    printf("\nKhoi luong toi da: %d",Weight);
}

