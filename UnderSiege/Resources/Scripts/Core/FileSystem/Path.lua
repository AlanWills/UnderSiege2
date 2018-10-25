local path = { }

path.sep = "\\"

local function at(s,i)
    return string.sub(s, i,i)
end

function path.combine(path1, path2, ...)
    if select('#',...) > 0 then
        local p = path.combine(path1,path2)
        local args = {...}
        for i = 1, #args do
            p = path.combine(p, args[i])
        end
        return p
    end

    local endc = at(path1, #path1)
    if endc ~= path.sep and endc ~= "" then
        path1 = path1..path.sep
    end

    return path1..path2
end

return path