//mondai1_005.c
//演習 前回の課題のデータを構造体で定義し、男性体重でソートし結果を表⽰せよ
//chcp 65001
#include <stdio.h>
#include <string.h>

typedef struct Data {
char pref[10];
double m_height;
double m_weight;
double f_height;
double f_weight;
} P_Data;

void swap( P_Data *, P_Data * );
void Quicksort(P_Data *, int, int);
int Partition(P_Data *, int, int);

int main() {
    int i;
    size_t len,len2;
    char pref[47][10] = {"北海道", "青森", "岩手", "宮城", "秋田", "山形", "福島", "茨城", "栃木", "群馬", "埼玉", "千葉", "東京", "神奈川", "新潟", "富山", "石川", "福井", "山梨", "長野", "岐阜", "静岡", "愛知", "三重", "滋賀", "京都", "大阪", "兵庫", "奈良", "和歌山", "鳥取", "島根", "岡山", "広島", "山口", "徳島", "香川", "愛媛", "高知", "福岡", "佐賀", "長崎", "熊本", "大分", "宮崎", "鹿児島", "沖縄"};
    // char pref[47][10] = {"北海道\0", "青森\0", "岩手\0", "宮城\0", "秋田\0", "山形\0", "福島\0", "茨城\0", "栃木\0", "群馬\0", "埼玉\0", "千葉\0", "東京\0", "神奈川\0", "新潟\0", "富山\0", "石川\0", "福井\0", "山梨\0", "長野\0", "岐阜\0", "静岡\0", "愛知\0", "三重\0", "滋賀\0", "京都\0", "大阪\0", "兵庫\0", "奈良\0", "和歌山\0", "鳥取\0", "島根\0", "岡山\0", "広島\0", "山口\0", "徳島\0", "香川\0", "愛媛\0", "高知\0", "福岡\0", "佐賀\0", "長崎\0", "熊本\0", "大分\0", "宮崎\0", "鹿児島\0", "沖縄\0"};

    P_Data p_data[47];

    int num_prefecture = 47;

    for ( i=0; i<num_prefecture; i++ ) {
        len = strlen(pref[i]);
        // strcpy( p_data[i].pref, pref[i]);
        strncpy( p_data[i].pref, pref[i], sizeof(pref[i]));
        len2 = strlen(pref[i]);
        printf("%2d:%s:%d --> %s:%d ",i,pref[i],len,p_data[i].pref,len2 );
        if(p_data[i].pref[6] == '\0'){
            printf("6");
        }
        if (p_data[i].pref[7] == '\0') {
            printf("7");
        }if(p_data[i].pref[6] != '\0' && p_data[i].pref[7] != '\0'){
            printf("else");
        }
        printf("\n");

    }


    //printf(" %s, %5.1lf, %5.1lf, %5.1lf %5.1lf \n", p_data[12].pref, p_data[12].m_weight, p_data[12].m_height,p_data[12].f_height, p_data[12].f_weight );

    // printf("県名  : 男重,  男長,  女重,  女長\n\n");

    // for ( i=0; i<num_prefecture; i++ ) {
    //    printf("%s",p_data[i].pref );
        //都道府県名が漢字2字の場合はスペースを入れる
        //普通は7文字目だが、なぜか新潟だけ6番目がヌル文字になる
        // if(p_data[i].pref[7] == '\0' || p_data[i].pref[6] == '\0'){
    //    if(p_data[i].pref[7] == '\0'){
    //        printf("  :");
    //    }else{
    //        printf(":");
    //    }

   //}

    return 0;
}

void swap( P_Data *num_x, P_Data *num_y ) {
    P_Data tmp;
    tmp = *num_x;
    *num_x = *num_y;
    *num_y = tmp;
}

void Quicksort(P_Data *pointer, int num_p, int num_r){
    int num_pivot;
    if(num_p < num_r){
        num_pivot = Partition(pointer, num_p, num_r);
        Quicksort(pointer, num_p, num_pivot-1);
        Quicksort(pointer, num_pivot+1, num_r);
    }
}

int Partition(P_Data *pointer, int num_p, int num_r){
    int num_i, num_j;
    P_Data num_pivot;
    num_pivot = pointer[num_r];
    num_i = num_p - 1;
    for(num_j = num_p; num_j < num_r; num_j++){
        if(pointer[num_j].m_weight >= num_pivot.m_weight){
            num_i++;
            swap(&pointer[num_i], &pointer[num_j]);
        }
    }
    swap(&pointer[num_i+1], &pointer[num_r]);
    return num_i+1;
}



