# algorithms_test
## AStar
- 概念
    - 开放列表：openSet
    - 关闭列表：closeSet
    - 启发函数：heuristic，一般视作h
        - 曼哈顿距离：D*(dx + dy)
        - 欧几里得距离：D * sqrt(dx * dx + dy * dy)
    - 起点到节点的代价：g
    - 节点到终点的代价：f = g + h
