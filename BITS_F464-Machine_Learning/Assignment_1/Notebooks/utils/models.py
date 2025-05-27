import numpy as np
import pandas as pd
import matplotlib.pyplot as plt
from utils.utils_ml import generate_confusion_matrix

class Perceptron():
    def __init__(self, dataset: pd.DataFrame, is_normalized: bool = False):
        # Initializing the dataset
        self.dataset = dataset
        if is_normalized:
            self.dataset = self.dataset.fillna(dataset.mean(numeric_only=True))  

        self.training_dataset = self.dataset.iloc[:int(
            0.67*self.dataset.shape[0]), :]

        self.testing_dataset = self.dataset.iloc[int(
            0.67*self.dataset.shape[0]):, :]
        
        if is_normalized:
            mean = self.training_dataset.iloc[:, :-1].mean(numeric_only=True)
            std = self.training_dataset.iloc[:, :-1].std()
            self.training_dataset.iloc[:, :-1] = (self.training_dataset.iloc[:, :-1] - mean)/std
            self.testing_dataset.iloc[:, :-1] = (self.testing_dataset.iloc[:, :-1] - mean)/std 

        # Add bias column to start
        self.training_dataset.insert(30, column="bias", value = 1)
        self.testing_dataset.insert(30, column="bias", value = 1)

        # print(self.training_dataset.head())
        # print(self.testing_dataset.head())

        # Split data into train and test
        self.X_train = self.training_dataset.iloc[:, :-1].values
        self.y_train = self.training_dataset.iloc[:, -1].values
        self.X_test = self.testing_dataset.iloc[:, :-1].values
        self.y_test = self.testing_dataset.iloc[:, -1].values
        # print(self.y_train, self.y_test)

        # Make an initial array of w
        self.w = np.zeros(self.dataset.shape[1])

        # We keep track of w and the accuracy where we get max accuracy
        self.max_accuracy = {"w": self.w,
                             "training_accuracy": 0.0, "testing_accuracy": 0.0, "confusion_matrix": None}

        self.accuracy_array_testing = []
        self.accuracy_array_training = []

        self.y_test_predicted = []

    # This function is brute forcing through all the possible values
    def train(self) -> np.ndarray:
        # We initialize training_done to False
        training_done = False

        count = 0

        # We loop till it's done
        while(not training_done):
            # We iterate through all the training data
            for index, x in enumerate(self.X_train):
                # We use the formula w*x*l <= 0
                if (self.y_train[index] * np.dot(self.w, x)) <= 0:
                    # If yes, we add l*x
                    self.w += self.y_train[index]*x
                    # We keep track of count
                    count += 1
                    break
            else:
                training_done = True
        print(f"Vector w: {self.w}")
        print(f"Number of Iterations: {count}")
        return self.w

    def epoch_train(self, epoch: int = 100, learning_rate: float = 1.0, initial_weights: np.ndarray = None) -> np.ndarray:
        # Here instead of using while loop, we use epochs
        count = 0

        # If initial weights is given, we use the same and continue
        # Otherwise we start from scratch
        if(initial_weights is None):
            self.w = np.zeros(self.dataset.shape[1])
        else:
            self.w = initial_weights

        # We keep a max_accuracy to keep track of the w/accuracy for which we get max_accuracy
        self.max_accuracy = {
            "w": self.w,
            "training_accuracy": self.check_training_accuracy(),
            "testing_accuracy": self.check_test_accuracy(),
            "confusion_matrix": self.show_confusion_matrix()
        }

        # Loop through all the epochs
        for _ in range(epoch):
            # Check accuracy
            testing_accuracy = self.check_test_accuracy()
            training_accuracy = self.check_training_accuracy()
            # Store that accuracy in the accuracy array
            self.accuracy_array_testing.append(testing_accuracy)
            self.accuracy_array_training.append(training_accuracy)
            # If accuracy > max, change max
            if(training_accuracy > self.max_accuracy["training_accuracy"]):
                self.max_accuracy = {
                    "w": self.w,
                    "training_accuracy": self.check_training_accuracy(),
                    "testing_accuracy": self.check_test_accuracy(),
                    "confusion_matrix": self.show_confusion_matrix()
                }

            for index, x in enumerate(self.X_train):
                # We use the formula w*x*l <= 0
                if (self.y_train[index] * np.dot(self.w, x)) <= 0:
                    # If yes, we add l*x
                    self.w += self.y_train[index]*x*learning_rate
                    # We keep track of count
                    count += 1
                    break
        # Printing result in the end
        print(f"Vector w: {self.w}")
        print(f"Number of Iterations: {count}")
        return self.w
    
    def predict(self, x_input):
        return 1 if np.dot(self.w, x_input) > 0 else -1

    # We plot the accuracy of the function, by using the accuracy
    def plot_accuracy(self):
        plt.title("Testing vs training accuracy")
        plt.plot([i for i in range(len(self.accuracy_array_testing))], self.accuracy_array_testing, label='Test')
        plt.plot([i for i in range(len(self.accuracy_array_training))], self.accuracy_array_training, label='Train')
        plt.legend()

    # A function to find the accuracy score of the data for the testing data
    def check_test_accuracy(self):
        y_predicted = [self.predict(x) for x in self.X_test]
        self.y_test_predicted = y_predicted
        return generate_confusion_matrix(y_pred=np.array(y_predicted), y_true=self.y_test)[0]

    # A function to find the accuracy score of the data for the training data
    def check_training_accuracy(self):
        y_predicted = [self.predict(x) for x in self.X_train]
        # print(y_predicted, self.y_train)
        return generate_confusion_matrix(y_pred=np.array(y_predicted), y_true=self.y_train)[0]

    def show_confusion_matrix(self):
        cm = generate_confusion_matrix(y_true=(self.y_test), y_pred=np.array(self.y_test_predicted))

        accuracy = cm[0]
        precision = cm[1]
        recall = cm[2]
        f1 = cm[3]
        
        return accuracy, precision, f1, recall


class FisherLDA:
    def __init__(self, dataset: pd.DataFrame, is_feature_engineered = 0):
        # Initializing the dataset
        self.dataset = dataset
        
        if is_feature_engineered == 1:
            self.dataset = self.dataset.fillna(dataset.mean(numeric_only=True))

        self.training_dataset = self.dataset.iloc[:int(
            0.67*self.dataset.shape[0]), :]

        self.testing_dataset = self.dataset.iloc[int(
            0.67*self.dataset.shape[0]):, :]
        
        if is_feature_engineered == 1:
            mean = self.training_dataset.iloc[:, :-1].mean(numeric_only=True)
            std = self.training_dataset.iloc[:, :-1].std()
            self.training_dataset.iloc[:, :-1] = (self.training_dataset.iloc[:, :-1] - mean)/std
            self.testing_dataset.iloc[:, :-1] = (self.testing_dataset.iloc[:, :-1] - mean)/std 

        # Training Dataset
        # Splitting the dataset category wise for the training data
        # This is done in fisher, because we need separate data
        # 1 is benign and 0 is malign
        self.training_dataset_benign = self.training_dataset[
            self.training_dataset["cancer_type"] == 1]
        self.training_dataset_malign = self.training_dataset[
            self.training_dataset["cancer_type"] == 0]

        # Convert these into values
        self.X_train_values_benign = self.training_dataset_benign.iloc[:, :-1].values
        self.X_train_values_malign = self.training_dataset_malign.iloc[:, :-1].values

        print(f"Shape of Benign Training Data (incl. output column): {self.training_dataset_benign.shape}")
        print(f"Shape of Malignant Training Data (incl. output column): {self.training_dataset_malign.shape}")

        # Datasets for accuracy
        self.X_train = self.training_dataset.iloc[:, :-1].values
        self.y_train = self.training_dataset.iloc[:, -1].values
        self.X_test = self.testing_dataset.iloc[:, :-1].values
        self.y_test = self.testing_dataset.iloc[:, -1].values

        # Make an initial array of w
        self.w = np.zeros(self.dataset.shape[1] - 1)

        # For the final answer, we need to P(malign | w,x) = P(w,x | malign)P(malign)
        # We take P(w, x | malign) as a normal distribution
        self.probability_malign = self.training_dataset_malign.shape[0] / (
            self.training_dataset_benign.shape[0] + self.training_dataset_malign.shape[0])
        self.probability_benign = self.training_dataset_benign.shape[0] / (
            self.training_dataset_benign.shape[0] + self.training_dataset_malign.shape[0])
        
        self.covariance_matrix_s1 = np.zeros(
            (self.X_train_values_benign.shape[1],
             self.X_train_values_benign.shape[1])
        )
        self.covariance_matrix_s2 = np.zeros(
            (self.X_train_values_malign.shape[1],
             self.X_train_values_malign.shape[1])
        )


    def train(self):
        # Using notebook notations:
        # Category 1: Benign
        # Category 2: Malignant

        # m1bar = mean of features for category 1
        # m2bar = mean of features for category 2
        m1bar = self.X_train_values_benign.mean(axis=0)
        m2bar = self.X_train_values_malign.mean(axis=0)
        
        # print(m1bar)
        # print(m2bar)

        covariance_matrix_s1 = np.zeros(
            (self.X_train_values_benign.shape[1],
             self.X_train_values_benign.shape[1])
        )
        covariance_matrix_s2 = np.zeros(
            (self.X_train_values_malign.shape[1],
             self.X_train_values_malign.shape[1])
        )

        # s1_component is giving us Sigma(x_n - m1bar)(x_n - m1bar)T
        for index, x in enumerate(self.X_train_values_benign):
            col_matrix = (x - m1bar).reshape((x - m1bar).shape[0], 1)
            row_matrix = col_matrix.T

            # Just a note for future: np.transpose does not work on 1D array, since it counts as 0D vector
            # col_matrix = np.transpose(x - m1bar)
            # print(col_matrix.shape)

            covariance_matrix_s1 += (col_matrix * row_matrix)

        # s2_component is giving us Sigma(x_n - m2bar)(x_n - m2bar)T
        for index, x in enumerate(self.X_train_values_malign):
            col_matrix = (x - m2bar).reshape((x - m2bar).shape[0], 1)
            row_matrix = col_matrix.T

            # Just a note for future: np.transpose does not work on 1D array, since it counts as 0D vector
            # col_matrix = np.transpose(x - m1bar)
            # print(col_matrix.shape)

            covariance_matrix_s2 += (col_matrix * row_matrix)

        s_w = (covariance_matrix_s1) + (covariance_matrix_s2)
        s_w_inv = np.linalg.inv(s_w)

        self.w = np.matmul(
            s_w_inv, (m2bar - m1bar).reshape((m2bar - m2bar).shape[0], 1))

        return self.w

    def predict(self, x_input):
        # List of all the projected points
        x_malign = [np.matmul(self.w.T,x)[0] for x in self.X_train_values_malign]
        x_benign = [np.matmul(self.w.T,x)[0] for x in self.X_train_values_benign]
        
        # Here each set of 3 lines calculates
        # 1/(2pi*sigma)^0.5 * e^(-(1/2*sigma)(x-mu)^2)
        # This is just giving us P(w_tx)
        scalar_s1 = (1. / ((2 * np.pi) ** (1 / 2.))) * (1 / ((np.std(x_benign))))
        x_sub_u_s1 = np.subtract(np.matmul(self.w.T,x_input.reshape(x_input.shape[0], 1)), np.mean(x_benign))
        p_s1 = scalar_s1 * np.exp(-np.dot(x_sub_u_s1, x_sub_u_s1.T) / (np.std(x_benign) * np.std(x_benign) * 2.))
        
        scalar_s2 = (1. / ((2 * np.pi) ** (1 / 2.))) * (1 / (np.std(x_malign)))
        x_sub_u_s2 = np.subtract(np.matmul(self.w.T,x_input.reshape(x_input.shape[0], 1)), np.mean(x_malign))
        p_s2 = scalar_s2 * np.exp(-np.dot(x_sub_u_s2, x_sub_u_s2.T) / (np.std(x_malign) * np.std(x_malign) * 2.))        
        
        # print(f"Benign: {str(p_s1[0][0]).ljust(30)} Malignant: {str(p_s2[0][0]).ljust(30)}")
        probs =  [p_s1 * self.probability_benign, p_s2 * self.probability_malign]
        
        # While returning 0 returns the probabilities while 1 returns the prediction
        return [probs, 1 if probs[0] > probs[1] else 0]
    
    def check_training_accuracy(self):
        y_predicted = [self.predict(x)[1] for x in self.X_train]
        print(f"Training Predicted: {y_predicted}")
        return generate_confusion_matrix(y_pred=np.array(y_predicted), y_true=self.y_train)[0]
    
    def check_testing_accuracy(self):
        y_predicted = [self.predict(x)[1] for x in self.X_test]
        self.y_test_predicted = y_predicted
        print(f"Testing Predicted: {y_predicted}")
        return generate_confusion_matrix(y_pred=np.array(y_predicted), y_true=self.y_test)[0]
    
    # Required seaborn
    # def plot_training_data(self):
    #     benign = [self.predict(x)[0][0][0][0] for x in self.X_train_values_benign]
    #     malign = [self.predict(x)[0][1][0][0] for x in self.X_train_values_malign]
    #     sns.kdeplot(benign)
    #     sns.kdeplot(malign)
        
    def get_normal_distribution(self, x_input, mean, stan_dev):
        return 1/(np.sqrt(2*np.pi*stan_dev*stan_dev)) * np.exp(-(x_input-mean)**2/(2*stan_dev*stan_dev))
        
    def plot_normal_distribution(self):
        x_malign = [np.matmul(self.w.T,x)[0] for x in self.X_train_values_malign]
        x_benign = [np.matmul(self.w.T,x)[0] for x in self.X_train_values_benign]
  
        # Calculating mean and standard deviation
        mean_malign = np.mean(x_malign)
        sd_malign = np.std(x_malign)
        mean_benign = np.mean(x_benign)
        sd_benign = np.std(x_benign)
        
        # Generate 1000 samples from the normal distribution
        samples_malign = np.random.normal(mean_malign, sd_malign, 1000)
        samples_benign = np.random.normal(mean_benign, sd_benign, 1000)

        # Plot a histogram of the samples_malign
        # Plot histograms of the data with overlaid PDFs
        plt.hist(samples_malign, bins=50, density=True, alpha=0.5, color='blue', label='Malignant')
        plt.hist(samples_benign, bins=50, density=True, alpha=0.5, color='green', label='Benign')

        # Create an array of random values
        x = np.linspace(-0.5, 0.5, 1000)
        
        # Calculate prob_dist_funcs for each class and plot them
        prob_dist_func_m = self.get_normal_distribution(x, mean_malign, sd_malign)
        prob_dist_func_b = self.get_normal_distribution(x, mean_benign, sd_benign)
        plt.plot(x, prob_dist_func_m, color='blue', label='Malignant prob_dist_func')
        plt.plot(x, prob_dist_func_b, color='green', label='Benign prob_dist_func')

        # Set the title and labels
        plt.title('Normal Distribution of malign and benign')
        plt.xlabel('X-axis')
        plt.ylabel('Y-axis')
        
        # Find intersection point of the prob_dist_funcs and plot it
        intersection = np.argwhere(np.diff(np.sign(prob_dist_func_m - prob_dist_func_b))).flatten()
        plt.plot(x[intersection], prob_dist_func_m[intersection], 'ro', markersize=10)

        # Add legend and axis labels
        plt.legend()
        plt.xlabel('LDA Component')
        plt.ylabel('Density')

        # Show the plot
        plt.show()
    
    def show_confusion_matrix(self):
        cm = generate_confusion_matrix(y_true=(self.y_test), y_pred=np.array(self.y_test_predicted))

        accuracy = cm[0]
        precision = cm[1]
        recall = cm[2]
        f1 = cm[3]
        
        return accuracy, precision, f1, recall


class LogReg():
    def __init__(self, dataset, is_feature_engineered = 0):
        # Initializing the dataset
        self.dataset = dataset        
        
        if is_feature_engineered == 1:
            self.dataset = self.dataset.fillna(dataset.mean(numeric_only=True))

        # Splitting training and testing datasets
        self.training_dataset = self.dataset.iloc[:int(
            0.67*self.dataset.shape[0]), :]
        self.testing_dataset = self.dataset.iloc[int(
            0.67*self.dataset.shape[0]):, :]
        
        if is_feature_engineered == 1:
            mean = self.training_dataset.iloc[:, :-1].mean(numeric_only=True)
            std = self.training_dataset.iloc[:, :-1].std()
            self.training_dataset.iloc[:, :-1] = (self.training_dataset.iloc[:, :-1] - mean)/std
            self.testing_dataset.iloc[:, :-1] = (self.testing_dataset.iloc[:, :-1] - mean)/std 

        
        # Defining separate w matrices for each gradient type        
        self.batch_w = np.zeros((self.training_dataset.shape[1] - 1, 1))
        self.mini_batch_w = np.zeros((self.training_dataset.shape[1] - 1, 1))
        self.stochastic_w = np.zeros((self.training_dataset.shape[1] - 1, 1))

        # Split data into train and test
        self.X_train = self.training_dataset.iloc[:, :-1].values
        self.y_train = self.training_dataset.iloc[:, -1].values
        self.X_test = self.testing_dataset.iloc[:, :-1].values
        self.y_test = self.testing_dataset.iloc[:, -1].values
        
        # Definish separate lists to store cost histories
        self.batch_cost_history = []
        self.mini_batch_cost_history = []
        self.stochastic_cost_history = []

        # A small value added to prevent the argument in the log() from being 0
        self.epsilon = 1e-100

    # Sigmoid function
    def get_sigmoid_value(self, z):
        if z >= 0:
            sig = (1/(1+np.exp(-z)))
        else:
            sig = (np.exp(z)/(1+np.exp(z)))
        # print(f"z: {z}, Value: {sig}")
        return sig

    # Batch Gradient Descent
    def batch_gradient_descent(self, target_values, input_values, learning_rate):
        # Make an array of true values
        y_true = target_values.reshape(target_values.shape[0], 1)      

        # Make an array to store predicted values
        y_pred = []

        # Iterating thorough all the samples in the training dataset
        for x in input_values:
            y_pred.append(self.get_sigmoid_value(
                np.matmul(self.batch_w.T, x.reshape(30, 1))[0][0]))
            
        y_pred = np.array(y_pred)

        # An array for differences
        difference = []
        difference = y_pred.reshape(y_pred.shape[0], 1) - y_true

        # Making a matrix to store the gradient values
        batch_grad = np.zeros((30, 1))

        # Iterating through the samples in training dataset the batch gradient
        for index, x in enumerate(input_values):
            batch_grad += (difference[index][0])*(x.reshape(30, 1))

        cost_history = []
        # Updating the batch_w matrix 
        self.batch_w -= learning_rate*batch_grad
        cost_history.append(self.cost_function(
            input_value=input_values, target_value=target_values, w=self.batch_w)/377)
        self.batch_cost_history += cost_history
        return self.batch_w

    # Batch Training Function
    def batch_train(self, lr, epochs):
        # We make it loop over epochs
        self.batch_cost_history = []
        for _ in range(epochs):
            # Find gradient and get the updated batch_w
            self.batch_w = self.batch_gradient_descent(target_values=self.y_train, input_values=self.X_train, learning_rate=lr)
        

        # iterations = []
        # iterations = [i for i in range(1, epochs+1)]
        # print(f"{self.batch_cost_history=}, {iterations=}")
        # plt.plot(iterations, self.batch_cost_history)
        # plt.show()
            
    # Mini Batch Gradient Descent
    def mini_batch_gradient_descent(self, target_values, input_values, batch_size, learning_rate):
        # Make an array of true values
        y_true = target_values.reshape(target_values.shape[0], 1)
        
        # Making a matrix to store the gradient values
        mini_batch_grad = np.zeros((self.training_dataset.shape[1] - 1, 1))

        cost_history = []
        # Defining a variable to store the cost in this epoch
        iter_cost = 0

        # Iterating through each sample in the training dataset to calculate the mini batch gradient
        for index, x in enumerate(input_values):
            y_pred = self.get_sigmoid_value(
                np.matmul(self.mini_batch_w.T, x.reshape(self.training_dataset.shape[1] - 1, 1))[0][0])
            difference = y_pred - y_true[index][0]
            # Making a matrix to store the mini batch gradient values
            mini_batch_grad += difference*(x.reshape(30, 1))
            if index % batch_size == 0 and index <= self.training_dataset.shape[0]//batch_size:
                self.mini_batch_w -= learning_rate*mini_batch_grad
                iter_cost += self.cost_function(
                    input_value=input_values, target_value=target_values, w=self.mini_batch_w)/37
            elif index == len(input_values)-1:
                self.mini_batch_w -= learning_rate*mini_batch_grad
                iter_cost += self.cost_function(
                    input_values, target_values, self.mini_batch_w)/37
            
        self.mini_batch_cost_history.append(iter_cost)
        return self.mini_batch_w       
    
    # Mini Batch Training Function
    def mini_batch_train(self, lr, epochs):
        self.mini_batch_cost_history = []
        for _ in range(epochs):
            self.mini_batch_w = self.mini_batch_gradient_descent(
                target_values=self.y_train, input_values=self.X_train, learning_rate=lr, batch_size=10)
        
        # iterations = []
        # iterations = [i for i in range(1, epochs+1)]
        # print(f"{self.batch_cost_history=}, {iterations=}")
        # plt.plot(iterations, self.mini_batch_cost_history)
        # plt.show()
    
    # Stochastic Gradient Descent
    def stochastic_gradient_descent(self, target_values, input_values, learning_rate):
        y_true = target_values.reshape(target_values.shape[0], 1)
        cost_history = []
        # Defining a variable to store the cost in this epoch
        iter_cost = 0
        
        for index, x in enumerate(input_values):
            y_pred = self.get_sigmoid_value(
                np.matmul(self.stochastic_w.T, x.reshape(self.training_dataset.shape[1] - 1, 1))[0][0])
            difference = y_pred - y_true[index][0]
            stochastic_grad = difference*(x.reshape(30, 1))
            self.stochastic_w -= learning_rate*stochastic_grad
            iter_cost += self.cost_function(
                input_value=input_values,target_value=target_values,w=self.stochastic_w)
        self.stochastic_cost_history.append(iter_cost)
        return self.stochastic_w

    # Stochastic Training Function
    def stochastic_train(self, lr, epochs):
        self.stochastic_cost_history = []
        for _ in range(epochs):
            self.stochastic_w = self.stochastic_gradient_descent(
                target_values=self.y_train, input_values=self.X_train, learning_rate=lr)
            
        # iterations = []
        # iterations = [i for i in range(1, epochs+1)]
        # print(f"{self.batch_cost_history=}, {iterations=}")
        # plt.plot(iterations, self.stochastic_cost_history)
        # plt.show()
    
    # Predict function
    def predict(self, x_input, descent_type, thresh):
        if(descent_type == "Batch"):
                w = self.batch_w        
        elif(descent_type == "Mini-Batch"):
            w = self.mini_batch_w
        elif(descent_type == "Stochastic"):
                w = self.stochastic_w
        
        # Here input should be the column vector with 30rows and 1 column
        return 1 if self.get_sigmoid_value(np.matmul(w.T, x_input.reshape(30, 1))[0][0]) > thresh else 0
    
    def cost_function(self, input_value, target_value, w):
        y_true = target_value.reshape(target_value.shape[0], 1)
        cost = 0
        for index, x in enumerate(input_value):
            y_t = y_true[index][0]
            pred = self.get_sigmoid_value(
                np.matmul(w.T, x.reshape(30, 1))[0][0])
            # print(f"{pred=}")
            cost += -(y_t * np.log(pred + self.epsilon) +
                      (1-y_t)*np.log(1-pred + self.epsilon))
        
        
        return cost

    # Function to check training accuracy
    # This function does not have any arguments
    def check_training_accuracy(self, descent_type, thresh):
        # Making an array to store the predicted values
        y_pred = []
        for x in self.X_train:
            y_pred.append(self.predict(x, descent_type, thresh))
        # print(y_pred)
        # print(self.y_test)
        # print(len(y_pred))
        # print(type(y_pred))
        return generate_confusion_matrix(y_pred=np.array(y_pred), y_true=self.y_train)[0]

    # Function to check testing accuracy
    def check_testing_accuracy(self, descent_type, thresh):
        
        # Making an array to store the predicted values
        y_pred = []
        for x in self.X_test:
            y_pred.append(self.predict(x, descent_type, thresh))
        # print(y_pred)
        self.y_test_pred = y_pred
        # print(accuracy_score(y_pred=y_pred, y_true=self.y_test))
        return generate_confusion_matrix(y_pred=np.array(y_pred), y_true=self.y_test)[0]

    # Confusion Matrix Function
    def show_confusion_matrix(self):
        cm = generate_confusion_matrix(y_true=(self.y_test), y_pred=np.array(self.y_test_pred))

        accuracy = cm[0]
        precision = cm[1]
        recall = cm[2]
        f1 = cm[3]
        
        return accuracy, precision, f1, recall

    def run_all_permutations(self, descents, thresholds, learning_rates, epochs, showGraph):
        iterations = []
        iterations = [i for i in range(1, epochs+1)]
        data_for_permutations = np.zeros((45, 5))
        counter = 0
        for d in descents:
            for lr in learning_rates:
                for t in thresholds:  
                    if showGraph:
                        plt.title(f'Descent={d},LearningRate={lr},Threshold={t}')
                    if(d == "Batch"):
                        self.batch_train(lr, epochs)
                        if showGraph:
                            plt.plot(iterations, self.batch_cost_history)
                            plt.xlabel('Iterations')
                            plt.ylabel('Cost Function')                        
                            plt.show()
                    elif(d == "Mini-Batch"):
                        self.mini_batch_train(lr, epochs)
                        if showGraph:
                            plt.plot(iterations, self.mini_batch_cost_history)
                            plt.xlabel('Iterations')
                            plt.ylabel('Cost Function')
                            plt.show()
                    elif(d == "Stochastic"):
                        self.stochastic_train(lr, 10)
                        if showGraph:
                            plt.plot(iterations, self.stochastic_cost_history)
                            plt.xlabel('Iterations')
                            plt.ylabel('Cost Function')
                            plt.show()
                    print(f"Descent: {d} Learning Rate: {lr} Threshold: {t}\nTraining Accuracy: {self.check_training_accuracy(d, t)}\nTesting Accuracy: {self.check_testing_accuracy(d, t)}\n")
                    
                    cm = self.show_confusion_matrix()
                    data_for_permutations[counter][0] = self.check_training_accuracy(d, t)
                    data_for_permutations[counter][1] = cm[0]
                    data_for_permutations[counter][2] = cm[1]
                    data_for_permutations[counter][3] = cm[2]
                    data_for_permutations[counter][4] = cm[3]
                    
                    counter += 1
        return data_for_permutations
