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
    char pref[47][10] = {"北海道", "青森", "岩手", "宮城", "秋田", "山形", "福島", "茨城", "栃木", "群馬", "埼玉", "千葉", "東京", "神奈川", "新潟", "富山", "石川", "福井", "山梨", "長野", "岐阜", "静岡", "愛知", "三重", "滋賀", "京都", "大阪", "兵庫", "奈良", "和歌山", "鳥取", "島根", "岡山", "広島", "山口", "徳島", "香川", "愛媛", "高知", "福岡", "佐賀", "長崎", "熊本", "大分", "宮崎", "鹿児島", "沖縄"};
    double m_height[47] = {171.2, 171.3, 170.6, 170.8, 171.9, 170.6, 170.0, 170.6, 170.6, 170.8, 171.2, 170.8, 171.4, 171.3, 170.9, 171.4, 171.4, 170.8, 170.9, 170.4, 170.2, 170.9, 170.4, 170.9, 171.0, 171.5, 170.7, 170.6, 171.1, 170.6, 171.2, 170.5, 170.4, 169.6, 170.0, 170.3, 170.4, 170.6, 169.7, 170.3, 170.8, 170.7, 170.6, 170.1, 170.1, 170.4, 169.5};
    double m_weight[47] = {63.7, 64.9, 64.0, 63.2, 65.9, 63.5, 63.0, 63.5, 63.6, 63.9, 62.4, 61.6, 62.2, 61.2, 63.4, 62.5, 63.2, 62.2, 63.6, 61.6, 62.1, 61.6, 60.6, 63.1, 61.5, 62.0, 62.5, 62.2, 61.4, 63.2, 62.4, 63.7, 61.5, 61.3, 61.5, 64.4, 63.1, 63.6, 61.8, 62.1, 62.2, 63.6, 62.5, 63.3, 63.5, 62.2, 62.8};
    double f_height[47] = {158.0, 158.2, 157.7, 157.5, 157.7, 158.1, 157.5, 158.0, 157.9, 157.5, 158.4, 158.1, 158.9, 158.5, 158.4, 158.5, 158.1, 159.2, 158.1, 157.5, 157.6, 157.8, 157.3, 158.1, 158.0, 158.4, 157.8, 157.9, 158.4, 157.9, 157.6, 157.9, 157.3, 157.2, 157.5, 157.4, 157.1, 157.3, 156.8, 157.9, 157.4, 157.5, 158.0, 158.0, 156.8, 158.0, 156.3};
    double f_weight[47] = {53.0, 54.5, 54.6, 53.2, 53.1, 52.8, 53.5, 53.4, 54.1, 53.2, 53.0, 52.4, 51.7, 51.9, 53.3, 53.0, 52.6, 54.2, 53.1, 52.5, 52.5, 51.8, 51.6, 52.5, 52.0, 51.7, 52.6, 52.3,    52.5, 53.0, 52.0, 52.5, 52.6, 51.9, 51.5, 53.3, 52.0, 53.3, 52.4, 52.6, 52.9, 53.1, 53.1,    54.0, 52.6, 53.0, 51.4};

    P_Data p_data[47];

    int num_prefecture = 47;

    for ( i=0; i<num_prefecture; i++ ) {
        strcpy( p_data[i].pref, pref[i]);
        p_data[i].m_height = m_height[i];
        p_data[i].m_weight = m_weight[i];
        p_data[i].f_height = f_height[i];
        p_data[i].f_weight = f_weight[i];
    }

    Quicksort(p_data, 0, num_prefecture-1);

    //printf(" %s, %5.1lf, %5.1lf, %5.1lf %5.1lf \n", p_data[12].pref, p_data[12].m_weight, p_data[12].m_height,p_data[12].f_height, p_data[12].f_weight );

    printf("県名  : 男重,  男長,  女重,  女長\n\n");

    for ( i=0; i<num_prefecture; i++ ) {
        printf("%s",p_data[i].pref );
        //都道府県名が漢字2字の場合はスペースを入れる
        //普通は7文字目だが、なぜか新潟だけ6番目がヌル文字になる
        if(p_data[i].pref[7] == '\0' || p_data[i].pref[6] == '\0'){
            printf("  :");
        }else{
            printf(":");
        }

        printf("%5.1lf, %5.1lf, %5.1lf, %5.1lf \n", p_data[i].m_weight, p_data[i].m_height, p_data[i].f_weight ,p_data[i].f_height );
    }

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



