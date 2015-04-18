#ifndef SLAYER_HPP
#define	SLAYER_HPP

#include <Engine/SpriteNode.hpp>

#include "misc.hpp"


class Slayer: public engine::SpriteNode {
	class ContactHandler: public engine::util::EventHandler<b2Contact*, bool> {
	protected:
		Slayer* m_slayer;
		size_t m_count;
	public:
		ContactHandler(Slayer* slayer): m_slayer(slayer), m_count(0) {}
		void handle(b2Contact*, bool);

        size_t GetCount() const {
        	return m_count;
        }
	};
protected:
	enum State {
		STANDING,
		RUNNING,
		ATTACKING,
	};
	sf::Vector2f m_velocityIncrease;
	sf::Vector2f m_maxVelocity;
	float m_jumpCooldown;
	WeaponType m_weaponType;
	State m_state;
	Node* m_weapon;
	ContactHandler m_contactHandler;
	float m_shootTime;
public:
	Slayer(engine::Scene* scene);
	virtual ~Slayer();

    void SetWeaponType(WeaponType weaponType);
	
	void PlayAni(std::string after="");

	virtual void SetFlipped(bool flipped);

	
protected:
	virtual void OnUpdate(sf::Time interval);

};

#endif	/* SLAYER_HPP */
