import numpy as np

def mse(y, y_hat):
    l = 0.5 * np.mean((y_hat-y)**2)
    return l

def mse_grad(X, y, y_hat):
    return (1./y.shape[0]) * (X.T @ (y_hat-y))

X         = [[8, 4], [4, 6], [9, 0], [2., 5], [3, 4]]
y         = [0., 1, 1, 1, 0]
w         = [0.1, 0.2, 0.3]
epochs    = 5
alpha     = 0.01
loss      = mse
loss_grad = mse_grad

X, y, w = np.asarray(X), np.asarray(y), np.asarray(w)

y, w = y.reshape(-1, 1), w.reshape(-1, 1)

X = np.c_[np.ones(X.shape[0], dtype=X.dtype), X]

for i in range(1, epochs+1):
    print(f"Epoch {i}")
    print(12*"-")
    y_hat = X @ w
    print(f"y_hat : {y_hat.ravel()}")
    l = loss(y, y_hat)
    print(f"loss : {l}")
    w_grad = loss_grad(X, y, y_hat)
    print(f"w_grad : {w_grad.ravel()}")
    w = w - alpha * w_grad
    print(f"w_new : {w.ravel()}")
    print(12*"-")
