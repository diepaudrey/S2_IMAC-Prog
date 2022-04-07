#include "tp4.h"
#include "mainwindow.h"

#include <QApplication>
#include <time.h>
#include <stdio.h>

MainWindow* w = nullptr;
using std::size_t;
using std::string;

int Heap::leftChild(int nodeIndex)
{
    return (nodeIndex*2 + 1);
}

int Heap::rightChild(int nodeIndex)
{
    return (nodeIndex*2 + 2);
}

void Heap::insertHeapNode(int heapSize, int value)
{
	// use (*this)[i] or this->get(i) to get a value at index i
    int i = heapSize;
    this->get(i) = value;

    while(i>0 && this->get(i)>this->get((i-1)/2)){
        swap(i, (i-1)/2);
        i = (i-1)/2;
    }
}

void Heap::heapify(int heapSize, int nodeIndex)
{
    // use (*this)[i] or this->get(i) to get a value at index i
    int largest = nodeIndex;
    int left = leftChild(nodeIndex);
    int right = rightChild(nodeIndex);


    //find largest
    if(left< heapSize && this->get(left) > this->get(largest)){
        largest = left;
    }


    if(right < heapSize && this->get(right) > this->get(largest)){
        largest = right;
    }

    //compare
    if(largest != nodeIndex ){
        this->swap(largest,nodeIndex);
        this->heapify(heapSize, largest);
    }

}

void Heap::buildHeap(Array& numbers)
{
    int sizeTab = numbers.size();


    for(int i=0; i<sizeTab ; i++){
        insertHeapNode(sizeTab, numbers[i]);
    }


}

void Heap::heapSort()
{
    int heapSize = this->size();

    for(int i=heapSize-1; i>=0; i--){
        this->swap(0,i);
        this->heapify(i,0);
    }
}

int main(int argc, char *argv[])
{
	QApplication a(argc, argv);
    MainWindow::instruction_duration = 50;
    w = new HeapWindow();
	w->show();

	return a.exec();
}
