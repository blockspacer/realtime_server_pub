// automatically generated by the FlatBuffers compiler, do not modify

#ifndef FLATBUFFERS_GENERATED_BATTLEINFO_DEMOBATTLE_H_
#define FLATBUFFERS_GENERATED_BATTLEINFO_DEMOBATTLE_H_

#include "flatbuffers/flatbuffers.h"


namespace DemoBattle {

struct BattlePlayerCharacter;
struct BattleInfo;

struct BattlePlayerCharacter FLATBUFFERS_FINAL_CLASS : private flatbuffers::Table {
  int32_t character_id() const { return GetField<int32_t>(4, 0); }
  const flatbuffers::String *name() const { return GetPointer<const flatbuffers::String *>(6); }
  int16_t base_hp() const { return GetField<int16_t>(8, 100); }
  int16_t base_mana() const { return GetField<int16_t>(10, 100); }
  int16_t physical_attack() const { return GetField<int16_t>(12, 10); }
  int16_t magical_attack() const { return GetField<int16_t>(14, 10); }
  int16_t physical_defense() const { return GetField<int16_t>(16, 10); }
  int16_t magical_defense() const { return GetField<int16_t>(18, 10); }
  int16_t speed() const { return GetField<int16_t>(20, 10); }
  bool Verify(flatbuffers::Verifier &verifier) const {
    return VerifyTableStart(verifier) &&
           VerifyField<int32_t>(verifier, 4 /* character_id */) &&
           VerifyField<flatbuffers::uoffset_t>(verifier, 6 /* name */) &&
           verifier.Verify(name()) &&
           VerifyField<int16_t>(verifier, 8 /* base_hp */) &&
           VerifyField<int16_t>(verifier, 10 /* base_mana */) &&
           VerifyField<int16_t>(verifier, 12 /* physical_attack */) &&
           VerifyField<int16_t>(verifier, 14 /* magical_attack */) &&
           VerifyField<int16_t>(verifier, 16 /* physical_defense */) &&
           VerifyField<int16_t>(verifier, 18 /* magical_defense */) &&
           VerifyField<int16_t>(verifier, 20 /* speed */) &&
           verifier.EndTable();
  }
};

struct BattlePlayerCharacterBuilder {
  flatbuffers::FlatBufferBuilder &fbb_;
  flatbuffers::uoffset_t start_;
  void add_character_id(int32_t character_id) { fbb_.AddElement<int32_t>(4, character_id, 0); }
  void add_name(flatbuffers::Offset<flatbuffers::String> name) { fbb_.AddOffset(6, name); }
  void add_base_hp(int16_t base_hp) { fbb_.AddElement<int16_t>(8, base_hp, 100); }
  void add_base_mana(int16_t base_mana) { fbb_.AddElement<int16_t>(10, base_mana, 100); }
  void add_physical_attack(int16_t physical_attack) { fbb_.AddElement<int16_t>(12, physical_attack, 10); }
  void add_magical_attack(int16_t magical_attack) { fbb_.AddElement<int16_t>(14, magical_attack, 10); }
  void add_physical_defense(int16_t physical_defense) { fbb_.AddElement<int16_t>(16, physical_defense, 10); }
  void add_magical_defense(int16_t magical_defense) { fbb_.AddElement<int16_t>(18, magical_defense, 10); }
  void add_speed(int16_t speed) { fbb_.AddElement<int16_t>(20, speed, 10); }
  BattlePlayerCharacterBuilder(flatbuffers::FlatBufferBuilder &_fbb) : fbb_(_fbb) { start_ = fbb_.StartTable(); }
  BattlePlayerCharacterBuilder &operator=(const BattlePlayerCharacterBuilder &);
  flatbuffers::Offset<BattlePlayerCharacter> Finish() {
    auto o = flatbuffers::Offset<BattlePlayerCharacter>(fbb_.EndTable(start_, 9));
    return o;
  }
};

inline flatbuffers::Offset<BattlePlayerCharacter> CreateBattlePlayerCharacter(flatbuffers::FlatBufferBuilder &_fbb,
   int32_t character_id = 0,
   flatbuffers::Offset<flatbuffers::String> name = 0,
   int16_t base_hp = 100,
   int16_t base_mana = 100,
   int16_t physical_attack = 10,
   int16_t magical_attack = 10,
   int16_t physical_defense = 10,
   int16_t magical_defense = 10,
   int16_t speed = 10) {
  BattlePlayerCharacterBuilder builder_(_fbb);
  builder_.add_name(name);
  builder_.add_character_id(character_id);
  builder_.add_speed(speed);
  builder_.add_magical_defense(magical_defense);
  builder_.add_physical_defense(physical_defense);
  builder_.add_magical_attack(magical_attack);
  builder_.add_physical_attack(physical_attack);
  builder_.add_base_mana(base_mana);
  builder_.add_base_hp(base_hp);
  return builder_.Finish();
}

struct BattleInfo FLATBUFFERS_FINAL_CLASS : private flatbuffers::Table {
  const flatbuffers::String *host() const { return GetPointer<const flatbuffers::String *>(4); }
  int32_t player1_id() const { return GetField<int32_t>(6, 0); }
  const flatbuffers::String *player1_name() const { return GetPointer<const flatbuffers::String *>(8); }
  const flatbuffers::Vector<flatbuffers::Offset<BattlePlayerCharacter>> *player1_characters() const { return GetPointer<const flatbuffers::Vector<flatbuffers::Offset<BattlePlayerCharacter>> *>(10); }
  int32_t player2_id() const { return GetField<int32_t>(12, 0); }
  const flatbuffers::String *player2_name() const { return GetPointer<const flatbuffers::String *>(14); }
  const flatbuffers::Vector<flatbuffers::Offset<BattlePlayerCharacter>> *player2_characters() const { return GetPointer<const flatbuffers::Vector<flatbuffers::Offset<BattlePlayerCharacter>> *>(16); }
  bool Verify(flatbuffers::Verifier &verifier) const {
    return VerifyTableStart(verifier) &&
           VerifyField<flatbuffers::uoffset_t>(verifier, 4 /* host */) &&
           verifier.Verify(host()) &&
           VerifyField<int32_t>(verifier, 6 /* player1_id */) &&
           VerifyField<flatbuffers::uoffset_t>(verifier, 8 /* player1_name */) &&
           verifier.Verify(player1_name()) &&
           VerifyField<flatbuffers::uoffset_t>(verifier, 10 /* player1_characters */) &&
           verifier.Verify(player1_characters()) &&
           verifier.VerifyVectorOfTables(player1_characters()) &&
           VerifyField<int32_t>(verifier, 12 /* player2_id */) &&
           VerifyField<flatbuffers::uoffset_t>(verifier, 14 /* player2_name */) &&
           verifier.Verify(player2_name()) &&
           VerifyField<flatbuffers::uoffset_t>(verifier, 16 /* player2_characters */) &&
           verifier.Verify(player2_characters()) &&
           verifier.VerifyVectorOfTables(player2_characters()) &&
           verifier.EndTable();
  }
};

struct BattleInfoBuilder {
  flatbuffers::FlatBufferBuilder &fbb_;
  flatbuffers::uoffset_t start_;
  void add_host(flatbuffers::Offset<flatbuffers::String> host) { fbb_.AddOffset(4, host); }
  void add_player1_id(int32_t player1_id) { fbb_.AddElement<int32_t>(6, player1_id, 0); }
  void add_player1_name(flatbuffers::Offset<flatbuffers::String> player1_name) { fbb_.AddOffset(8, player1_name); }
  void add_player1_characters(flatbuffers::Offset<flatbuffers::Vector<flatbuffers::Offset<BattlePlayerCharacter>>> player1_characters) { fbb_.AddOffset(10, player1_characters); }
  void add_player2_id(int32_t player2_id) { fbb_.AddElement<int32_t>(12, player2_id, 0); }
  void add_player2_name(flatbuffers::Offset<flatbuffers::String> player2_name) { fbb_.AddOffset(14, player2_name); }
  void add_player2_characters(flatbuffers::Offset<flatbuffers::Vector<flatbuffers::Offset<BattlePlayerCharacter>>> player2_characters) { fbb_.AddOffset(16, player2_characters); }
  BattleInfoBuilder(flatbuffers::FlatBufferBuilder &_fbb) : fbb_(_fbb) { start_ = fbb_.StartTable(); }
  BattleInfoBuilder &operator=(const BattleInfoBuilder &);
  flatbuffers::Offset<BattleInfo> Finish() {
    auto o = flatbuffers::Offset<BattleInfo>(fbb_.EndTable(start_, 7));
    return o;
  }
};

inline flatbuffers::Offset<BattleInfo> CreateBattleInfo(flatbuffers::FlatBufferBuilder &_fbb,
   flatbuffers::Offset<flatbuffers::String> host = 0,
   int32_t player1_id = 0,
   flatbuffers::Offset<flatbuffers::String> player1_name = 0,
   flatbuffers::Offset<flatbuffers::Vector<flatbuffers::Offset<BattlePlayerCharacter>>> player1_characters = 0,
   int32_t player2_id = 0,
   flatbuffers::Offset<flatbuffers::String> player2_name = 0,
   flatbuffers::Offset<flatbuffers::Vector<flatbuffers::Offset<BattlePlayerCharacter>>> player2_characters = 0) {
  BattleInfoBuilder builder_(_fbb);
  builder_.add_player2_characters(player2_characters);
  builder_.add_player2_name(player2_name);
  builder_.add_player2_id(player2_id);
  builder_.add_player1_characters(player1_characters);
  builder_.add_player1_name(player1_name);
  builder_.add_player1_id(player1_id);
  builder_.add_host(host);
  return builder_.Finish();
}

inline const DemoBattle::BattleInfo *GetBattleInfo(const void *buf) { return flatbuffers::GetRoot<DemoBattle::BattleInfo>(buf); }

inline bool VerifyBattleInfoBuffer(flatbuffers::Verifier &verifier) { return verifier.VerifyBuffer<DemoBattle::BattleInfo>(); }

inline void FinishBattleInfoBuffer(flatbuffers::FlatBufferBuilder &fbb, flatbuffers::Offset<DemoBattle::BattleInfo> root) { fbb.Finish(root); }

}  // namespace DemoBattle

#endif  // FLATBUFFERS_GENERATED_BATTLEINFO_DEMOBATTLE_H_
