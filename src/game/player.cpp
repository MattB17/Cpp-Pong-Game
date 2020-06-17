#include "player.h"
#include "constants.h"

Player::Player(std::string name, 
               std::unique_ptr<Paddle> paddle, 
               std::unique_ptr<Vec2D> scoreDisplayPos)
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

Player::Player(const Player& source) {
  name_ = source.name_;
  *paddle_ = *(source.paddle_);
  *scoreDisplayPos_ = *(source.scoreDisplayPos_);
  score_ = source.score_;
}

Player& Player::operator=(const Player& source) {
  if (*this != source) {
    name_ = source.name_;
    *paddle_ = *(source.paddle_);
    *scoreDisplayPos_ = *(source.scoreDisplayPos_);
    score_ = source.score_;
  }
  return *this;
}

Player::Player(Player&& source) {
  name_ = source.name_;
  paddle_ = std::move(source.paddle_);
  scoreDisplayPos_ = std::move(source.scoreDisplayPos_);
  score_ = source.score_;
  
  name_ = "";
  paddle_ = nullptr;
  scoreDisplayPos_ = nullptr;
  score_ = 0;
}

Player& Player::operator=(Player&& source) {
  if (*this != source) {
    name_ = source.name_;
    paddle_ = std::move(source.paddle_);
    scoreDisplayPos_ = std::move(source.scoreDisplayPos_);
    score_ = source.score_;
    
    name_ = "";
    paddle_ = nullptr;
    scoreDisplayPos_ = nullptr;
    score_ = 0;
  }
  return *this;
}

bool Player::operator==(const Player& other) {
  return ((name_ == other.name_) &&
          (*paddle_ == *(other.paddle_)) &&
          (*scoreDisplayPos_ == *(other.scoreDisplayPos_)) &&
          (score_ == other.score_));
}

bool Player::operator!=(const Player& other) {
  return ((name_ != other.name_) ||
          (*paddle_ != *(other.paddle_)) ||
          (*scoreDisplayPos_ != *(other.scoreDisplayPos_)) ||
          (score_ != other.score_));
}
    
    

void Player::UpdatePaddlePosition(float elapsedTime) {
  paddle_->UpdatePosition(elapsedTime);
}

void Player::UpdatePaddleVelocityY(float y) {
  paddle_->UpdateVelocityY(y);
}