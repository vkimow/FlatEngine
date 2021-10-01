#include "FlatEngine/Core/Input/Elements/Press/PressableMouse.h"
#include "FlatEngine/Core/Objects/ObjectComponent.h"
#include "FlatEngine/Core/Main/Events/Action.h"

namespace Flat::Engine::Actors
{
	class FLAT_ENGINE_API ButtonComponent : public Core::Objects::ObjectComponent
	{
	public:
		ButtonComponent(float height, float width);
		~ButtonComponent();

	protected:
		virtual void Update() override;

	public:
		bool IsOverlaped() const { return isOverlaped; }
		bool IsClicked() const { return isClicked; }

	private:
		bool IsOverlaping(sf::Vector2f position);

		void Overlap();
		void Click();
		void Release();

	public:
		CreateAction(void, OnButtonClicked)
		CreateAction(void, OnButtonOverlaped)

	private:
		Core::Input::PressableMouse click;
		float height;
		float width;

		bool isOverlaped;
		bool isClicked;

	};
}