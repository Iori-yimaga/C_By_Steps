//
// Created by JokerMss on 2020/6/10.
// һֻ����5Ǯ��һֻĸ��3Ǯ����ֻС��һǮ
// ��Ǯ�ټ�����
//
// ��ٷ�--->����ѭ��

#include "stdio.h"
int main(){
    int hens, roosters, chicken;
    int maxH = 100 / 3;
    int maxR = 100 / 5;
    int maxC = 100 / (1 / 3.0);
    for(roosters = 0; roosters <= maxR; roosters++){
        for (int hens = 0; hens <= maxH; hens++) {
            for (int chicken = 0; chicken <= 100; chicken++) {
                if((roosters * 5 + hens * 3 + chicken/3.0 == 100) && (roosters + hens + chicken == 100)){
                    printf("������%dֻ,ĸ����%dֻ,С��%dֻ\n", roosters, hens, chicken);
                }
            }
        }
    }
    return 0;
}
