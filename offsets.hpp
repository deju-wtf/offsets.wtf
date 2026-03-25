#pragma once

// Auto-generated Rust IL2CPP Main Offsets
// Namespace aliases for the most commonly used classes

#include "sdk.hpp"
#include <cstdint>

/* Namespace aliases for main Rust classes */
namespace offsets
{
	namespace BaseCombatEntity = sdk::BaseCombatEntity;
	namespace BasePlayer = sdk::BasePlayer;
	namespace BaseProjectile = sdk::BaseProjectile;
	namespace RecoilProperties = sdk::RecoilProperties;
	namespace PlayerModel = sdk::PlayerModel;
	namespace PlayerEyes = sdk::PlayerEyes;
	namespace ItemDefinition = sdk::ItemDefinition;
} // namespace offsets

/* Helper templates for memory operations */
template<typename T>
inline T read(std::uintptr_t address) {
	if (!address) return T{};
	return *reinterpret_cast<T*>(address);
}

template<typename T>
inline void write(std::uintptr_t address, T value) {
	if (!address) return;
	*reinterpret_cast<T*>(address) = value;
}

/* Offset chain helper */
inline std::uintptr_t follow_chain(std::uintptr_t base, std::initializer_list<std::uintptr_t> offsets) {
	std::uintptr_t address = base;
	for (auto offset : offsets) {
		if (!address) return 0;
		address = read<std::uintptr_t>(address + offset);
	}
	return address;
}

/* Common offset chains for Rust game structures */
namespace chains
{
	/* BaseProjectile -> RecoilProperties */
	inline std::uintptr_t get_recoil_properties(std::uintptr_t projectile) {
		return read<std::uintptr_t>(projectile + sdk::BaseProjectile::recoil);
	}

} // namespace chains

/* Usage Examples:
 *
 * // Access offsets directly (via namespace aliases)
 * auto health = read<float>(entity + offsets::BaseCombatEntity::health);
 * auto position = read<Vector3>(player + offsets::BasePlayer::position);
 *
 * // Use pre-built chains
 * auto player_model = chains::get_player_model(player);
 * auto player_eyes = chains::get_player_eyes(player);
 * auto held_entity = chains::get_held_entity(player);
 * auto health = chains::get_health(entity);
 *
 * // Follow custom chains
 * auto result = follow_chain(player, {
 *     offsets::BasePlayer::inventory,
 *     offsets::Inventory::containerBelt
 * });
 */
