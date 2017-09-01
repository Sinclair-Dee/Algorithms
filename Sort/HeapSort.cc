public void heapadjust(int [] array, int parent, int length){
    int temp = array[parent];//temp保存当前父亲结点
    int child = 2*parent + 1;
    while(child < length){
        //如果有右孩子结点并且右孩子结点的值大于左孩子结点，这选取右孩子结点
        if(child + 1 < length && array[child] < array[child] + 1){
            child++;
        }
        //如果父亲结点的值已经大于孩子结点的值，则直接结束
        if(temp > array[child]){
            break;
        }
        //选取孩子结点的值赋给父亲结点
        array[parent] = array[child];
        //选取孩子结点的左孩子结点，继续向下筛选
        parent = child;
        child = 2*child + 1;
    array[parent] = temp;
    }
}