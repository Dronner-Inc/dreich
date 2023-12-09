#include "component_registry.h"

#include "transform.h"
#include "renderable.h"

#include <resources/resource_manager.h>

namespace wind {
    namespace stdgame {
         map<
            string, std::function<
                void(
                    entt::registry&, entt::entity,
                    doom::Container*
                )
            >
        > ComponentRegistry::builders;

        void ComponentRegistry::addComponent(
            string name,
            std::function<void(
                entt::registry&, entt::entity,
                doom::Container*
            )> func
        ) {
            builders.insert(std::make_pair(
                name, func
            ));
        }

        void ComponentRegistry::build(
            entt::registry& registry,
            entt::entity entity,
            string component,
            doom::Container* object
        ) {
            if (!builders.contains(component)) {
                log().error() << "ComponentRegistry: failed build component: [" << component << "]";
                return;
            }

            builders[component](registry, entity, object);
        }

        void ComponentRegistry::init() {
            addComponent("stdgame.transform",
                [](entt::registry& registry, entt::entity entity, doom::Container* dom) {
                    Transform transform;

                    auto position = dom->getObject("position");
                    if (position && position->isContainer()) {
                        auto pos = (doom::Container*)position;
                        
                        auto x = pos->getObject("x");
                        auto y = pos->getObject("y");
                        auto z = pos->getObject("z");

                        if (x && x->isValue()) transform.position.x = ((doom::Value*)x)->asFloat();
                        if (y && y->isValue()) transform.position.y = ((doom::Value*)y)->asFloat();
                        if (z && z->isValue()) transform.position.z = ((doom::Value*)z)->asFloat();
                    }

                    auto rotation = dom->getObject("rotation");
                    if (rotation && rotation->isContainer()) {
                        auto rot = (doom::Container*)rotation;
                        
                        auto x = rot->getObject("x");
                        auto y = rot->getObject("y");
                        auto z = rot->getObject("z");

                        if (x && x->isValue()) transform.rotation.x = ((doom::Value*)x)->asFloat();
                        if (y && y->isValue()) transform.rotation.y = ((doom::Value*)y)->asFloat();
                        if (z && z->isValue()) transform.rotation.z = ((doom::Value*)z)->asFloat();
                    }

                    auto scale = dom->getObject("scale");
                    if (scale && scale->isContainer()) {
                        auto scl = (doom::Container*)scale;
                        
                        auto x = scl->getObject("x");
                        auto y = scl->getObject("y");
                        auto z = scl->getObject("z");

                        if (x && x->isValue()) transform.scale.x = ((doom::Value*)x)->asFloat();
                        if (y && y->isValue()) transform.scale.y = ((doom::Value*)y)->asFloat();
                        if (z && z->isValue()) transform.scale.z = ((doom::Value*)z)->asFloat();
                    }

                    registry.emplace_or_replace<Transform>(entity, transform);
                }
            );

            addComponent("stdgame.renderable",
                [](entt::registry& registry, entt::entity entity, doom::Container* dom) {
                    auto mesh = dom->getObject("mesh");
                    if (!mesh || !mesh->isValue()) {
                        log().error() << "stdgame.renderable must have string mesh field";
                        return;
                    }

                    auto texture = dom->getObject("texture");
                    if (!texture || !texture->isValue()) {
                        log().error() << "stdgame.renderable must have string texture field";
                        return;
                    }

                    auto shader = dom->getObject("shader");
                    if (!shader || !shader->isValue()) {
                        log().error() << "stdgame.renderable must have shader texture field";
                        return;
                    }

                    auto rmesh = resources::get<renderer::Mesh>(((doom::Value*)mesh)->asString().c_str());
                    auto rtexture = resources::get<renderer::Texture>(((doom::Value*)texture)->asString().c_str());
                    auto rshader = resources::get<renderer::Shader>(((doom::Value*)shader)->asString().c_str());

                    registry.emplace_or_replace<Renderable>(entity, rmesh, rtexture, rshader);
                }
            );
        }
    }
}