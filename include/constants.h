#ifndef CONSTANTS_H
#define CONSTANTS_H

#include <cstddef>

constexpr std::size_t kFramesPerSecond{60};
constexpr std::size_t kCountWaitTime{1000};
constexpr std::size_t kMsPerFrame{1000 / kFramesPerSecond};
constexpr std::size_t kScreenWidth{1280};
constexpr std::size_t kScreenHeight{720};
constexpr int kBallWidth{15};
constexpr int kBallHeight{15};
constexpr int kPaddleWidth{10};
constexpr int kPaddleHeight{100};
constexpr float kPaddleSpeed{1.0f};
constexpr float kBallSpeed{1.5f};
constexpr float kScoreYPos{20.0f};

#endif