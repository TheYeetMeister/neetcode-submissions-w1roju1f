import torch
import torch.nn as nn
from torchtyping import TensorType

class Solution(nn.Module):
    inputNodes = 28 * 28
    layerOneNodes = 512
    outputNodes = 10
    p = 0.2
    
    def __init__(self):
        super().__init__()
        torch.manual_seed(0)
        self.first_layer = nn.Linear(self.inputNodes, self.layerOneNodes)
        self.ReLUActivation = nn.ReLU()
        self.dropout = nn.Dropout(p = self.p)
        self.final_layer = nn.Linear(self.layerOneNodes, self.outputNodes)
    
    def forward(self, images: TensorType[float]) -> TensorType[float]:
        # Return the model's prediction to 4 decimal places
        torch.manual_seed(0)

        inputs = self.first_layer(images)
        inputs = self.ReLUActivation(inputs)
        inputs = self.dropout(inputs)

        inputs = self.final_layer(inputs)
        inputs = torch.sigmoid(inputs)

        return torch.round(inputs, decimals = 4)
