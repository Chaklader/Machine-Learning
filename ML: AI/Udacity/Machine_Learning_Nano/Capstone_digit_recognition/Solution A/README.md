# P5 Capstone: Digit Recognition in Natural Images

1. Setup Environment:

Setup Python environment 2.7.x (I used 2.7.12) and install the following packages:
 - numpy
 - six
 - scipy
 - PIL
 - matplotlib
 - tensorflow
I would recommend using anaconda to setup python environment (https://www.continuum.io/downloads)

Now since, we are all setup with python we can install TensorFlow refer https://www.tensorflow.org/versions/r0.11/get_started/index.html

Setup TensorFlow on CPU or GPU (NVIDIA only) accoriding to your system for Python 2.7.x

NOTE: Performance will depend on how you configure your system GPU will be much faster mine was GeForce GTX 960M-2GB - Training time was about 8mins and CPU 6700HQ was approximately 1hr.

Great! we are ready to rock and roll! just one minor directory setup required

Now lets setup your working directory, your initial tree should look like as folows:
myproject(name of your directory)
├── README.md
├── downloads (empty directory)
├── pickles (empty directoruy)
├── saved_models (empty directory)
└── svhn.ipynb (main project file)

2 Now run: `jupyter notebook svhn.ipnb`

and follow the instructions there

Your final working directly tree should look like tree below:

├── README.md
├── downloads
│   ├── test_32x32.mat (test dataset)
│   └── train_32x32.mat (train dataset)
├── pickles
│   └── svhn.pickle (processed data)
├── saved_models
│   ├── SVHN_MODEL.ckpt (trained model)
│   ├── SVHN_MODEL.ckpt.meta
│   └── checkpoint
└── svhn.ipynb

