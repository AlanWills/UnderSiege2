LuaComponentDataConverter.register("KeyboardActivator", 
{
    ["Attributes"] = 
    {
        ["ActivationKey"] = 
        {
            ["Name"] = "activation_key",
            ["Type"] = "string",
            ["Default Value"] = "Unknown",
			["Is Reference"] = true
        },
        ["DeactivationKey"] = 
        {
            ["Name"] = "deactivation_key",
            ["Type"] = "string",
            ["Default Value"] = "Unknown",
			["Is Reference"] = true
        },
        ["InputMode"] = 
        {
            ["Name"] = "mode",
            ["Type"] = "string",
            ["Default Value"] = "Toggle",
            ["Is Reference"] = true
        }
    },

    ["SetValues"] = function(converter, component)
        local activator = component:asKeyboardActivator()
        
        activator:setActivationKey(converter:findAttribute("activation_key"):asString())
        activator:setDeactivationKey(converter:findAttribute("deactivation_key"):asString())
        activator:setInputMode(converter:findAttribute("mode"):asString())
    end
})