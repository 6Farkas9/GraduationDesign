import torch
import torch.nn as nn
from torch.autograd import Variable

# input_size = 二倍知识点数
# output_size = 知识点数

class IPDKT(nn.Module):
    def __init__(self,input_size, hidden_size, num_layer, output_size):
        super(IPDKT,self).__init__()
        self.input_size = input_size
        self.output_size = output_size
        self.hidden_size = hidden_size
        self.num_layers = num_layer

        self.lstm = nn.LSTM(self.input_size, self.hidden_size, self.num_layers, batch_first = True)
        self.kt_fc1 = nn.Linear(self.hidden_size, self.hidden_size)
        self.kt_fc2 = nn.Linear(self.hidden_size, self.output_size)

        self.ik_fc1 = nn.Linear(self.hidden_size, self.hidden_size)
        self.ik_fc2 = nn.Linear(self.hidden_size, self.output_size)
    
    def forward(self, x):
        # device = x.device
        # h0 = Variable(torch.zeros(self.num_layers, x.size(0), self.hidden_size)).to(device)
        out_lstm, _ = self.lstm(x)

        out_kt_fc1 = torch.relu(self.kt_fc1(out_lstm))
        out_kt_fc2 = self.kt_fc2(out_kt_fc1)
        out_kt = torch.sigmoid(out_kt_fc2)

        out_ik_fc1 = torch.relu(self.ik_fc1(out_lstm))
        out_ik_fc2 = self.ik_fc2(out_ik_fc1)
        out_ik = torch.sigmoid(out_ik_fc2)

        return out_kt, out_ik



        