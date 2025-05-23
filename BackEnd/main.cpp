﻿#include <iostream>
#include <torch/script.h>
#include <torch/torch.h>
#include <vector>
#include <filesystem>
#include "crow.h"

int main() {

    crow::SimpleApp app; //define your crow application

    //define your endpoint at the root directory
    CROW_ROUTE(app, "/")([](){
        return "Hello world";
    });

    //set the port, set the app to run on multiple threads, and run the app
    app.port(18080).multithreaded().run();

    // std::cout << "starting..." << std::endl;

    //  try {
    //      // 1. 检查CUDA
    //      std::cout << "\n=== 系统检查 ===" << std::endl;
    //      std::cout << "CUDA可用: " << torch::cuda::is_available() << std::endl;
    //      std::cout << "CUDA设备数: " << torch::cuda::device_count() << std::endl;

    //      // 2. 加载模型
    //      std::cout << "\n=== 模型加载 ===" << std::endl;
    //      torch::jit::Module model;
    //      try {
    //          /*std::filesystem::path model_path = "D:/Desktop/GraduationDesign/GraduationDesign/DeepLearning/KT/PT/IPDKT_use.pt";
    //          if (!std::filesystem::exists(model_path)) {
    //              throw std::runtime_error("文件不存在");
    //          }
    //          auto abs_path = std::filesystem::absolute(model_path).string();
    //          std::cout << abs_path << std::endl;*/

    //          std::string abs_path = R"(D:\Desktop\GraduationDesign\GraduationDesign\DeepLearning\KT\PT\IPDKT_use.pt)";

    //          model = torch::jit::load(abs_path);
    //          std::cout << "模型加载成功!" << std::endl;
    //      } catch (const std::exception& e) {
    //          std::cerr << "模型加载失败: " << e.what() << std::endl;
    //          return -1;
    //      }

    //      // 3. 创建测试输入
    //      std::cout << "\n=== 创建输入 ===" << std::endl;
    //      auto input = torch::rand({1, 1, 220}).to(at::kCUDA);
    //      std::cout << "输入形状: " << input.sizes() << std::endl;

    //      // 4. 运行推理
    //      std::cout << "\n=== 运行推理 ===" << std::endl;
    //      std::vector<torch::jit::IValue> inputs;
    //      inputs.push_back(input);

    //      auto output = model.forward(inputs).toTuple();
    //      auto out_kt = output->elements()[0].toTensor();
    //      auto out_ik = output->elements()[1].toTensor();

    //      std::cout << "KT输出形状: " << out_kt.sizes() << std::endl;
    //      std::cout << "IK输出形状: " << out_ik.sizes() << std::endl;

    //  } catch (const std::exception& e) {
    //      std::cerr << "发生异常: " << e.what() << std::endl;
    //      return -1;
    //  }

    //  std::cout << "\n程序执行完成!" << std::endl;
    // return 0;

}