# Dispersion of Mobile Robots
This is the C++ implementation of the Dispersion of Mobile Robots in a Ring with Vertex Permutations, one of the algorithms [presented](https://arxiv.org/abs/1707.06391) at the International Conference on Distributed Computing and Networking, 2018.

[Agarwalla, A., Augustine, J., Moses Jr, W.K., Madhav, S.K. and Sridhar, A.K., 2018, January. Deterministic dispersion of mobile robots in dynamic rings. In Proceedings of the 19th International Conference on Distributed Computing and Networking (pp. 1-4).](https://dl.acm.org/doi/10.1145/3154273.3154294)

## Environment
- C++
- OpenMP

#### Please read Algorithm 1 in https://arxiv.org/abs/1707.06391 to understand this implementation.

## Getting Started
### Compile
```
g++ Dispersion.cpp -fopenmp -o Dispersion.out
```

### Run 
```
./Dispersion.out
```

#### Input
- Enter number nodes
- Enter each node configuration as number_of_robots Robot_IDs

#### Example  
![screenshot](https://github.com/madhavsankar/Mobile_Robots/blob/master/Run.png)

## Authors
* Madhav Sankar Krishnakumar
* Ankush Aggarwalla
* Arvind  Krishna Sridhar
* Dr. John Augustine
* Dr. William Moses Jr.
