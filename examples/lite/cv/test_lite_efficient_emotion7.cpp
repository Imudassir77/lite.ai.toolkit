//
// Created by DefTruth on 2021/7/24.
//

#include "lite/lite.h"

static void test_default()
{
  std::string onnx_path = "../../../hub/onnx/cv/face-emotion-recognition-enet_b0_7.onnx";
  std::string test_img_path = "../../../examples/lite/resources/test_lite_emotion.jpg";
  std::string save_img_path = "../../../logs/test_lite_emotion.jpg";

  lite::cv::face::attr::EfficientEmotion7 *efficient_emotion7 =
      new lite::cv::face::attr::EfficientEmotion7(onnx_path);

  lite::cv::types::Emotions emotions;
  cv::Mat img_bgr = cv::imread(test_img_path);
  efficient_emotion7->detect(img_bgr, emotions);

  lite::cv::utils::draw_emotion_inplace(img_bgr, emotions);

  cv::imwrite(save_img_path, img_bgr);

  std::cout << "Default Version Detected Emotion: " << emotions.text
            << ": " << emotions.score << std::endl;

  delete efficient_emotion7;

}

static void test_onnxruntime()
{
  std::string onnx_path = "../../../hub/onnx/cv/face-emotion-recognition-enet_b0_7.onnx";
  std::string test_img_path = "../../../examples/lite/resources/test_lite_emotion.jpg";
  std::string save_img_path = "../../../logs/test_lite_emotion.jpg";

  lite::onnxruntime::cv::face::attr::EfficientEmotion7 *efficient_emotion7 =
      new lite::onnxruntime::cv::face::attr::EfficientEmotion7(onnx_path);

  lite::onnxruntime::cv::types::Emotions emotions;
  cv::Mat img_bgr = cv::imread(test_img_path);
  efficient_emotion7->detect(img_bgr, emotions);

  lite::onnxruntime::cv::utils::draw_emotion_inplace(img_bgr, emotions);

  cv::imwrite(save_img_path, img_bgr);

  std::cout << "ONNXRuntime Version Detected Emotion: " << emotions.text
            << ": " << emotions.score << std::endl;

  delete efficient_emotion7;
}

static void test_mnn()
{

}

static void test_ncnn()
{

}

static void test_tnn()
{

}

static void test_lite()
{
  test_default();
  test_onnxruntime();
  test_mnn();
  test_ncnn();
  test_tnn();
}

int main(__unused int argc, __unused char *argv[])
{
  test_lite();
  return 0;
}
