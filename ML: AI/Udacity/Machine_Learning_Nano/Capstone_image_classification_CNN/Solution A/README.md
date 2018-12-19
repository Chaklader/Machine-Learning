# CIFAR10 Image Classification with CNN and Caffe
- Udacity Machine Learning Nanodegree Capstone project
- By Neo Xing, 2016/10

## About
### Outline
```
cifar10
├── READ.md
├── project_report.pdf
├── codes/                       # Caffe training model, configuration and scripts
│   ├── CIFAR10_explore.ipynb    # CIFAR10 data exploration (visualization, linear classifier, MPL)
│   ├── CIFAR10_CNN_Caffe.ipynb  # CIFAR10 CNN with Caffe (convnet, with dropout, caffenet)
│   └── ...
├── results/                     # training logs, images, report
├── project-example/             # original project examples
└── notes/                       # supplementary notes on cs231n and Caffe
```

### Main references
- [cs231n](cs231n.stanford.edu)
- [Caffe documentation and examples](caffe.berkeleyvision.org)
- [A Practical Introduction to Deep Learning with Caffe and Python](http://adilmoujahid.com/posts/2016/06/introduction-deep-learning-python-caffe/)
- [Wikipedia](https://www.wikipedia.org/)

### Environment
- Amazon Elastic Computing Cloud g2.x2large GPU instance
- Ubuntu 14.04 (AMI cs231n_caffe_torch7_keras_lasagne_v2)
- Requirements: `lmdb, opencv-python`

### Usage
- copy files in `cifar10/codes` to `caffe/examples/cifar10` directory
- update local path configurations in notebooks
- run `CIFAR10_explore.ipynb` and `CIFAR10_CNN_Caffe.ipynb`
- use `pandoc -o project_report.pdf project_report.md -V geometry:margin=0.75in` to generate report
- Codes and notes from references must follow original license, Others MIT
