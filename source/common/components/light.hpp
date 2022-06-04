#pragma once

#include "../ecs/component.hpp"
#include "../ecs/transform.hpp"
#include <unordered_map>
#include <string>
#include <type_traits>
#include <glm/glm.hpp>

namespace our {
    // An enum that defines the type of the light source
    enum class LightType {
        DIRECTIONAL,
        SPOT,
        POINT
    };
    class LightComponent : public Component {
    public:
        int lightType; // The type of the light
        glm::vec3 diffuse;
        glm::vec3 specular;
        glm::vec4 color;
        glm::vec3 attenuation; // x*d^2 + y*d + z
        glm::vec2 cone_angles; // x: inner_angle, y: outer_angle
        glm::vec3 initPosition;
        glm::vec3 initDirection;
        glm::vec3 position;
        glm::vec3 direction;
        std::string lightTypeStr;
        // Reads light parameters from the given json object
        void deserialize(const nlohmann::json& data) override;
        static std::string getID() { return "light"; }

        void calculatePosition (  glm::mat4 localToWorld );
        void calculateDirection(  glm::mat4 localToWorld);
    };

}