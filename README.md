# Introduction
这是中国科学院大学大二上学期选择性必修课程序设计与实验（c语言）大作业-五子棋，在wcg班获得第五名成绩。
<br>
实现方法是复杂的形式判断，枚举了活二，活三，冲三，活四，冲四等等等棋型，按照棋型赋分，而不是按照是否能走到五连珠的简单方法进行搜索。并且引入了随机化算法，至少面对同一个机器对手很难重复对局情况。~~搏一搏，单车变摩托！~~
<br>
由于判断复杂，搜索层数没法堆叠很高。望后人用并行编程技巧改进。
# Debugs
* 活四的优先度可能低于冲四
* 部分跳活三可能没法堵上
