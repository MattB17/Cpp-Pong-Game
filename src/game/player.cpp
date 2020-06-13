#include "player.h"
#include "constants.h"

Player::Player(std::string name, 
               std::unique_ptr<Paddle> paddle, 
               std::unique_ptr<const Vec2D> scoreDisplayPos)
  : name_(name), score_(0) {
  paddle_ = std::move(paddle);
  scoreDisplayPos_ = std::move(scoreDisplayPos);
}

Player::Player(std::string name, float paddle_x, float paddle_y, float score_x)
  : name_(name), score_(0) {
    // instantiate paddle
    std::unique_ptr<Vec2D> paddle_pos = std::make_unique<Vec2D>(paddle_x, paddle_y);
    std::unique_ptr<Vec2D> paddle_velocity = std::make_unique<Vec2D>(0.0f, 0.0f);
    paddle_ = std::make_unique<Paddle>(std::move(paddle_pos),
                                       std::move(paddle_velocity),
                                       kPaddleWidth,
                                       kPaddleHeight);
    
    // instantiate score display position
    scoreDisplayPos_ = std::make_unique<Vec2D>(score_x, kScoreYPos);
}
    
    

void Player::UpdatePaddlePosition(float elapsedTime) {
  paddle_->UpdatePosition(elapsedTime);
}

void Player::UpdatePaddleVelocityY(float y) {
  paddle_->UpdateVelocityY(y);
}