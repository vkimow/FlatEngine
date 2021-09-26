
namespace Flat::Core::Objects
{
	class GameObject;

	class ObjectComponent
	{
	private:
		friend class GameObject;

	protected:
		ObjectComponent();

	public:
		ObjectComponent(const ObjectComponent& component) = delete;
		ObjectComponent(ObjectComponent&& component) = delete;
		ObjectComponent& operator=(const ObjectComponent& component) = delete;
		ObjectComponent& operator=(ObjectComponent&& component) = delete;

		virtual ~ObjectComponent();

	public:
		void SetActive(bool value);
		bool IsActive() const;

	protected:
		virtual void Update() {};

	private:
		void SetGameObject(GameObject* gameObject);

	protected:
		GameObject* const GetGameObject() const { return gameObject; }

	private:
		GameObject* gameObject;
		bool isActive;
	};
}