#pragma once
#include <muQuat32.h>
#include <stdint.h>

namespace jointskleton {

const int32_t MAGIC_JOSK = (3 << 'j') | (2 << 'o') | (1 << 's') | 'k';

enum class SkeletonFlags : uint32_t {
  // joint の座標系が parent
  ParentRelative = 0x1,
  // 左手系
  LeftHanded = 0x1 << 1,
};

enum class HumanBones : uint16_t {
  Hips,
  Spine,
  Chest,
  UpperChest,
  Neck,
  Head,
  // legs
  LeftUpperLeg,
  LeftLowerLeg,
  LeftFoot,
  LeftToes,
  RightUpperLeg,
  RightLowerLeg,
  RightFoot,
  RightToes,
  // arms
  LeftShoulder,
  LeftUpperArm,
  LeftLowerArm,
  LeftHand,
  RightShoulder,
  RightUpperArm,
  RightLowerArm,
  RightHand,
  // left fingers
  LeftThumbMetacarpal,
  LeftThumbProximal,
  LeftThumbDistal,
  LeftIndexProximal,
  LeftIndexIntermediate,
  LeftIndexDistal,
  LeftMiddleProximal,
  LeftMiddleIntermediate,
  LeftMiddleDistal,
  LeftRingProximal,
  LeftRingIntermediate,
  LeftRingDistal,
  LeftLittleProximal,
  LeftLittleIntermediate,
  LeftLittleDistal,
  // right fingers
  RightThumbMetacarpal,
  RightThumbProximal,
  RightThumbDistal,
  RightIndexProximal,
  RightIndexIntermediate,
  RightIndexDistal,
  RightMiddleProximal,
  RightMiddleIntermediate,
  RightMiddleDistal,
  RightRingProximal,
  RightRingIntermediate,
  RightRingDistal,
  RightLittleProximal,
  RightLittleIntermediate,
  RightLittleDistal,
  // BVHの先端などの印
  Tip,
};

struct Joint {
  mu::quat32 quat;
  float x;
  float y;
  float z;
};
static_assert(sizeof(Joint) == 16, "Joint");

struct JointDefinition {
  // parentBone
  uint16_t parentBoneIndex;
  // HumanBones or any number
  uint16_t boneType;
  Joint initPose;
};
static_assert(sizeof(JointDefinition) == 20, "JointDefintion");

struct Skeleton {
  uint32_t magic = MAGIC_JOSK;
  char frameMagic[4] = {'s', 'k', 'd', 'f'};
  uint32_t skeletonId = 0;
  SkeletonFlags flags = {};
  JointDefinition definitions[70];
};
static_assert(sizeof(Skeleton) == 16 + 70 * 20, "Skeleton");

struct Frame {
  uint32_t magic = MAGIC_JOSK;
  char frameMagic[4] = {'f', 'r', 'a', 'm'};
  // このフレームが参照する Skeleton の ID。サーバーに問い合わせる
  uint32_t skeletonId = 0;
  // padding 兼用
  uint32_t flag = {};
  // std::chrono::nanoseconds
  uint64_t time = {};
  Joint joints[52];
};
static_assert(sizeof(Frame) == 24 + 832, "FrameSize");

} // namespace jointskleton
