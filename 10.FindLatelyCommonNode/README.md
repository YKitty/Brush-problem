题目：对于一个二叉树/二叉搜索树查找任意两个节点的最近公共祖先结点      
思路：      
对于二叉搜索树：    
因为二叉搜索的特点：进行前序遍历，每次将遍历得到的结点的数据和已知结点数据进行比较   
有三种情况：     
第一种：一个在结点的左边，一个在右边。所求结点就是这个结点     
第二种：两个都在结点的左边，或者都在右边     
这个时候只需要一直遍历下去就可以，直到一个结点在左边一个结点在右边    

对于普通的二叉树：   
看是否能将其改成三叉树，增加一个parent结点    
这样的话，就可以将其从两个已知结点处开始遍历，将其当作两个链表，然后求着两个链表的最近公共节点就可以了，这个结点就是所求点     

不能改变的话：      
就从根节点开始遍历，找出两条到已知结点的链表     
对于这两个已知链表，从这个两个链表中，直到最后一个相交结点就是所求结点了     

