//
// Created by Manju Muralidharan on 10/19/25.
//

#ifndef HEAP_H
#define HEAP_H

#include <iostream>
using namespace std;

struct MinHeap {
    int data[64];
    int size;

    MinHeap() { size = 0; }

    //push function with two parameters. idx = index of node at star
                                       //weightArr = array of nodes weight
    void push(int idx, int weightArr[]) {
        if (size >=64) {
            cout <<"Overflow detected"; //first checks for OF
            return;
        }
        int pos = size++;
        data[pos] = idx;
        upheap(pos,weightArr); //restores order after insert
    }

    //pop function with parameter weightArr
    int pop(int weightArr[]) {
        //sanity check
        if (size == 0) return -1;
        int minIndex = data[0];
        data[0] = data[--size];
        if (size > 0) {
            downheap(0,weightArr);
        }
        return minIndex;
    }

    //upheap function with parameters pos and weightArr
    //pos is the current index of the node being changed
    void upheap(int pos, int weightArr[]) {
        while (pos>0) {
            int parent = (pos-1)/2;
            if (weightArr[data[parent]] <= weightArr[data[pos]]) break;
            std::swap(data[parent], data[pos]);
            pos = parent;
        }
    }

    //downheap function with parameters pos and weightArr
    void downheap(int pos, int weightArr[]) {
        while (true) {
            int left = 2* pos +1;
            int right = left + 1;
            if (left >= size) break; //this means it has no kids

            int smallest = left;
            if (right <size && weightArr[data[right]]< weightArr[data[left]]) {
                smallest = right;
            }
            if (weightArr[data[pos]] <= weightArr[data[smallest]]) break;
            std::swap(data[pos],data[smallest]);
            pos = smallest;

        }
    }
};

#endif