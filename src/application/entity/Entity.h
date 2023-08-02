#include "../mesh/Mesh.h"

namespace app {
    struct Component {
        virtual uint hash() { return 0; }
    };

    class Entity {
    private:
        Entity* m_parent;
        std::list<Entity*> m_children;
        std::list<Component*> m_components;
    public:
        ~Entity();

        void bind(Entity*); 
        void unbind(Entity*);
        
        void addComponent(Component*);
        void removeComponent(Component*);


        template <typename TComponent>
        TComponent* getComponent() {
            for (auto component : m_components)
                if (typeid(*component) == typeid(TComponent)) 
                    return (TComponent*)component;
            return nullptr;
        }

        template <typename TComponent>
        bool hasComponent() {
            return (getComponent<TComponent>() != nullptr);
        }
    };
}