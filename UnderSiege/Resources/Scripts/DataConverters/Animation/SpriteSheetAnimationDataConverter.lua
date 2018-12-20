LuaComponentDataConverter.register("SpriteSheetAnimation", 
{
    ["attributes"] = 
    {
        ["SpriteSheetDimensions"] = 
        {
            ["Name"] = "sprite_sheet_dimensions",
            ["Type"] = "unsigned vec2",
            ["Default Value"] = "1, 1",
            ["Is Required"] = true,
            ["Is Reference"] = true
        },
        ["Looping"] = 
        {
            ["Name"] = "looping",
            ["Type"] = "bool",
            ["Default Value"] = "true"
        },
        ["PlayImmediately"] = 
        {
            ["Name"]= "play_immediately",
            ["Type"] = "bool",
            ["Default Value"] = "true"
        }
    },

    ["doSetValues"] = function(converter, component)
        local spriteSheetAnimation = component:asSpriteSheetAnimation()
        
        spriteSheetAnimation:setSpriteSheetDimensions(converter:findAttribute("sprite_sheet_dimensions"):asUVec2())
        spriteSheetAnimation:setLooping(converter:findAttribute("looping"):asBool())
        spriteSheetAnimation:setPlayImmediately(converter:findAttribute("play_immediately"):asBool())
    end
})

-- Change attributes and elements to only be constructible from DataConverter
-- and add new API for creating them similar to scriptable object fields
-- Maybe we should make that deserialization API/structure shared or something?
-- Create template specializations for certain types of SO fields - e.g. Prefab/Resource/ScriptableObject fields?
-- Go through data converters with new resource/path element - it'll do wonders
-- Go through all data converters and remove #includes for attributes and elements