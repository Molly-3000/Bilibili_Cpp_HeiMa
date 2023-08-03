#include"head.h"
/*
* STL map 键值对	关系式容器	高性能 高效率
* 
* 1、基本概念
*		map：
*		·容器中所有元素都是pair，即成对出现
*		·pair中first元素为key（键值，索引作用），second为value（实值）
*		·所有元素（pair）都会根据key自动排序
* 
* 2、本质：
*		map/multimap 属于管联式容器，底层结构是二叉树实现
* 
* 3、优点：
*		·可以根据key值 快速找到value值
*		
* 4、map 和 multimap 区别：
*		·map 不允许容器中有重复key值的元素
*		·multimap 允许容器中有重复key值的元素
*		
*		P.S.插入时，自动检测
* 
*/