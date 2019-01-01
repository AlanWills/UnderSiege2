LuaComponentDataConverter.register("KeyboardVisibility", 
{
    ["Attributes"] = 
    {
        ["VisibilityKey"] = 
        {
            ["Name"] = "visibility_key",
            ["Type"] = "string",
            ["Default Value"] = "Unknown",
			["Is Reference"] = true
        },
        ["InvisibilityKey"] = 
        {
            ["Name"] = "invisibility_key",
            ["Type"] = "string",
            ["Default Value"] = "Unknown",
			["Is Reference"] = true
        },
        ["InputMode"] = 
        {
            ["Name"] = "mode",
            ["Type"] = "string",
            ["Default Value"] = "Continuous",
            ["Is Reference"] = true
        }
    },

    ["SetValues"] = function(converter, component)
        local visibility = component:asKeyboardVisibility()
        
        visibility:setVisibilityKey(converter:findAttribute("visibility_key"):asString())
        visibility:setInvisibilityKey(converter:findAttribute("invisibility_key"):asString())
        visibility:setInputMode(converter:findAttribute("mode"):asString())
    end
})