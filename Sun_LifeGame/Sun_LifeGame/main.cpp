//
//  main.cpp
//  Sun_LifeGame
//
//  Created by apple on 17/1/4.
//  Copyright © 2017年 孙晓彤. All rights reserved.
//

#include <iostream>

//liveNum(),计算某个位置周围活细胞的数目
int liveNum(int i,int j,int array[40][40]){
    int surroundNum=0;
    for(int indexi=i-1;indexi<i+2;indexi++){
        for(int indexj=j-1;indexj<j+2;indexj++){
            if(!((indexi==i)&&(indexj==j))&&(indexi<40)&&(indexj<40)&&(indexi>-1)&&(indexj>-1)&&array[indexi][indexj]==1){
                ++surroundNum;
            }
        }
    }
    return surroundNum;
}

void change(int array[40][40]){
    int tmpArray[40][40];
    for(int i=0;i<40;i++){
        for(int j=0;j<40;j++){
            tmpArray[i][j]=array[i][j];
        }
    }
    for(int i=0;i<40;i++){
        for(int j=0;j<40;j++){
            if(liveNum(i,j,tmpArray)==3){
                array[i][j]=1;
            }
            else if(liveNum(i,j,tmpArray)!=2&&liveNum(i,j,tmpArray)!=3){
                array[i][j]=0;
            }
        }
    }
    
}

int main(int argc, const char * argv[]){
    int cellWorld[40][40];
    for(int i=0;i<40;i++){
        for(int j=0;j<40;j++)
            cellWorld[i][j]=0;
    }
    int x,y,times;
    while(scanf("%d,%d",&x,&y) && x!=-1 && y!=-1)
        // std::cin无法实现逗号作为分隔符
        cellWorld[x][y]=1;
    
    std::cin>>times;
    
    for(int i=0;i<40;i++){
        for(int j=0;j<40;j++){
            std::cout<<cellWorld[i][j]<<' ';
        }
        std::cout<<std::endl;
    }
    std::cout<<"After "<<times<<" generations"<<std::endl;
    for(;times>0;times--){
        change(cellWorld);
    }
    for(int i=0;i<40;i++){
        for(int j=0;j<40;j++){
            std::cout<<cellWorld[i][j]<<' ';
        }
        std::cout<<std::endl;
    }
}

