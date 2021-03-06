题目：数组中的逆序对     
举例：[7, 6, 8, 5] 这样的一个数组     
对于7：6 5 比他小，所以有两对逆序的     
对于6: 5 比他小，所以有一对逆序的     
对于8: 5 比他小，所以有一对逆序的    
总的来说这样数组就有2+1+1=4对逆序对     

思路：    
1. 直接暴力求解法：     
对于数组中的每一个数字都进行遍历，然后再次遍历这个数字后面的所有数字，判断有多少个数字比他小的，那么这个数字的逆序对就有多少个    
时间复杂度：O(n^2)     
空间复杂度：O(1)   ： 因为没有浪费空间只是在原有的空间上进行遍历而已      

2. 采用归并排序的方法：     
对于归并排序会将所有的数字分成一个一个的数字，然后，在对于这些数字依次进行合并判断有多少个逆序对，所以对于归并排序只是浪费空间换取了时间     
使用归并排序的思想来写着算法，只是对于归并排序的时候，合并的时候进行了修改，对于其他的地方还是和归并排序一样，没有发生改变   
合并：举例：     
[7] [6] [8] [5]    
这个进行合并的时候，首先合并的是[7] [6],[8] [5]     
判断7>6，所以逆序数加1    8>5，逆序数加1     
接下来合并[6 7]  [5 8]    
这个时候，首先拿出left(左边)的最后一个和right(右边)的最后一个进行比较     
如果大于的话，则逆序数增加right(右边的个数)，否则right(右边)最后的一个标记右边的最后一个指针--，直到把右边遍历完，或者左边遍历完     
如果left(左边)一直小于right(右边)，那么左边就会一直--,直到左边遍历完    

时间复杂度：O(NLogN)    
空间复杂度：O(N)    

书写的时候一些注意的细节：      
使用C++写的：    
对于归并排序要开辟一个空间，首先要对于这个数组进行拆分然后再次进行合并      
拆分的时候求的是，左右两边也就是开始和结尾之间数据个数的一半，然后再次进行递归拆分     
mid = (right - left) >> 1;    

在进行求有多少个逆序对的时候，因为我们需要用到前一个排好序的数组    
所以要将tmp中的数据赋值给v中，但是赋值的时候在循环中只需要判断一次即可，所以设置了一个标志flag    
开始的时候flag = true   
设置了之后flag = false; 随后就不会再次进行赋值了     










