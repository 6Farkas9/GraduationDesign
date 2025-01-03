import torch
import torch.nn as nn

class Model_PDBeta(nn.Module):
    def __init__(self,embedding_dim):
        super(Model_PDBeta,self).__init__()
        self.embedding_dim = embedding_dim
        self.linear_pu = nn.Linear(2 * self.embedding_dim, 1)
        self.linear_dv = nn.Linear(2 * self.embedding_dim, 1)
        self.linear_bv = nn.Linear(self.embedding_dim, 1)

    def forward(self, x):
        out_pu = torch.relu(self.linear_pu(x[0]))
        out_dv = torch.relu(self.linear_dv(x[1]))
        out_bv = torch.relu(self.linear_bv(x[2]))
        # out_dv = self.relu(out_linear)
        # out_linear = self.relu(self.linear(x.clone()))
        return out_pu, out_dv, out_bv
