BITS F464

# **Assignment 2**

# MACHINE LEARNING

![](RackMultipart20230629-1-thy1fw_html_a0243959dbc46b8f.png)

# ![](RackMultipart20230629-1-thy1fw_html_f344d4cad69336f5.png)

# Team Members

- Divyateja Pasupuleti 2021A7PS0075H
- Kumarasamy 2021A7PS0096H
- Adarsh Das 2021A7PS1511H

# Introduction

In the second assignment, we were tasked with creating 2 models, one from scratch, where we had to implement Naive Bayes' and the second being Artificial Neural Network using Pytorch.

# Part A

## Data preprocessing

We first replace all the '?' with the most frequently occurring value in that feature, then we convert the categorical data to nominal data, for example, the salaries are converted from \>50K and \<=50K to 0 and 1.

## Model 1: Naive Bayes

Naive Bayes is a probabilistic classification algorithm based on Bayes' theorem, which assumes that the features are conditionally independent given the class label. It calculates the probability of each class and the conditional probability of each feature given the class. Then it uses these probabilities to predict the class with the highest probability for a new data point. It is simple, fast, and works well with high-dimensional data.

In Naive Baye's Classifier, we assume that the features are all independent. Therefore, we can multiply the probabilities of the various features.

We then calculate the likelihood of each value of each feature for both salary \>50K and \<= 50K. We then use these likelihood values to predict the salary of the testing examples.
 We've split the data into training(67%) and testing(33%).

| **Feature** | **Statistic** |
| --- | --- |
| Accuracy | 87.66% |
| Precision | 70.76% |
| Recall | 83.10% |
| F1 | 76.44% |

## Model 2: KNN

KNN is a non-parametric, lazy learning algorithm used for classification and regression tasks. Given a new data point, KNN finds the K training examples closest to it in the feature space, and predicts the class label based on the majority vote of the K neighbors. The choice of K affects the classifier's performance, with smaller values of K leading to more flexible models and larger values leading to smoother decision boundaries. ![](RackMultipart20230629-1-thy1fw_html_eed99ff893f4ccbb.png)

For KNN we did an analysis of the data to get the best 'K' value and took the model with the same.

| **Feature** | **Statistic** |
| --- | --- |
| Accuracy | 83.76% |
| Precision | 71.57% |
| Recall | 52.73% |
| F1 | 60.72% |

##

## Model 3: Logistic Regression

Logistic regression is a linear binary classification model can be generalized to multi-class classification using techniques like one-vs-rest or multinomial logistic regression. It models the probability of a data point belonging to a particular class using the logistic function, and fits the model parameters by minimizing the log-loss (cross-entropy) between the true labels and the predicted probabilities. It is simple, interpretable, and works well for linearly separable data.

Due to the nature of logistic regeression, all categorical data were converted using one-hot encoding to achieve high accuracy and remove unnecessary bias.

| **Feature** | **Statistic** |
| --- | --- |
| Accuracy | 85.06% |
| Precision | 75.31% |
| Recall | 55.95% |
| F1 | 64.20% |

## Conclusion

![](RackMultipart20230629-1-thy1fw_html_c5a6712fca972648.png)
As seen above Naive Bayes classifier is the better option compared to KNN and Logreg. This is because Logreg works well with continuous data that is normalized. KNN also works better on continuous data. But Naive Bayes is defined for categorical data and works well in our case.

# Part B: Artificial Neural Network: MNIST

We are considering **100 Epochs** and dataset splits of 67% for Training and 33% for Testing. We have 2 variants of **Hidden layers 2 and 3,** 2 variants of the **Number of neurons in each hidden layer, 100 and 150** , and 3 variants of **Activation functions TanH, Sigmoid, and RelU.**

In the ANN Classification Reports, We have macro and micro accuracies. Macro accuracy takes an average of all accuracies, while micro adds all numerators and adds all denominators and does the division. It also contains each class's precision, recall, and f1 score.

We used Pytorch to make these artificial neural networks and used the torch datasets repository only. In ANN, we convert the image, which is a 28x28, into a 784-sized tuple which we feed into the network, and using backpropagation on the training data, we settle the weights. Then we use this network with on the testing dataset and get probabilities of the number being each number, and we use the argmax function to find which of them has the highest probability and take that as output.

###

###

###

###

###

###

### 2 HIDDEN LAYERS, 100 NEURONS, TanH ACTIVATION FUNCTION:

![](RackMultipart20230629-1-thy1fw_html_dd7e34e424e95ea6.png)

###

### 2 HIDDEN LAYERS, 100 NEURONS, Sigmoid ACTIVATION FUNCTION:

![](RackMultipart20230629-1-thy1fw_html_f89b8c59fe250141.png)

###

### 2 HIDDEN LAYERS, 100 NEURONS, RelU ACTIVATION FUNCTION:

![](RackMultipart20230629-1-thy1fw_html_7bf8143192c8aa52.png)

###

### 2 HIDDEN LAYERS, 150 NEURONS, TanH ACTIVATION FUNCTION:

![](RackMultipart20230629-1-thy1fw_html_244cd42818361677.png)

###

###

### 2 HIDDEN LAYERS, 150 NEURONS, Sigmoid ACTIVATION FUNCTION:

![](RackMultipart20230629-1-thy1fw_html_472308da9999d195.png)

###

###

### 2 HIDDEN LAYERS, 150 NEURONS, RelU ACTIVATION FUNCTION:

![](RackMultipart20230629-1-thy1fw_html_cd083c6336ed5648.png)

###

### 3 HIDDEN LAYERS, 100 NEURONS, TanH ACTIVATION FUNCTION:

![](RackMultipart20230629-1-thy1fw_html_b8bf9d56aa11a12b.png)

###

###

### 3 HIDDEN LAYERS, 100 NEURONS, Sigmoid ACTIVATION FUNCTION:

![](RackMultipart20230629-1-thy1fw_html_928697a520bcd87a.png)

###

### 3 HIDDEN LAYERS, 100 NEURONS, RelU ACTIVATION FUNCTION:

![](RackMultipart20230629-1-thy1fw_html_4bf0773c69ce34d4.png)

###

###

### 3 HIDDEN LAYERS, 150 NEURONS, TanH ACTIVATION FUNCTION:

![](RackMultipart20230629-1-thy1fw_html_805ab0cb0733405e.png)

###

###

### 3 HIDDEN LAYERS, 150 NEURONS, Sigmoid ACTIVATION FUNCTION:

![](RackMultipart20230629-1-thy1fw_html_38932b8eb13ea927.png)

###

###

### 3 HIDDEN LAYERS, 150 NEURONS, RelU ACTIVATION FUNCTION:

![](RackMultipart20230629-1-thy1fw_html_cd7c42da59e87c6a.png)

**3 HIDDEN LAYERS, 100 + 150 NEURONS, TanH ACTIVATION FUNCTION:**

![](RackMultipart20230629-1-thy1fw_html_6e6d47e2e0fe6b71.png)

**3 HIDDEN LAYERS, 100 + 150 NEURONS, Sigmoid ACTIVATION FUNCTION:**

![](RackMultipart20230629-1-thy1fw_html_b59017fce5fe0304.png)

**3 HIDDEN LAYERS, 100 + 150 NEURONS, RelU ACTIVATION FUNCTION:**

![](RackMultipart20230629-1-thy1fw_html_61ba03c5117bc7f4.png)

###

###

### Comparison of all ANN Models

![](RackMultipart20230629-1-thy1fw_html_c9e6259c32677e7d.png)

### CONCLUSION
- We observe that over 100 epochs, neural networks perform way better than other Machine Learning algorithms.
- The accuracy is similar between models, which would mean that these models have similar accuracies, and there is no statistically significant model compared to the other models.
- We also observe that TanH tends to have higher accuracy than Sigmoid and RelU in most cases. We are not concluding anything here but are just noting our observations.
- We also observe a slight increase in accuracy with an increase in neurons; this is because there is more capability for the model to learn from the data due to multiple data points.

![](RackMultipart20230629-1-thy1fw_html_d7dec09130297fd1.png)
