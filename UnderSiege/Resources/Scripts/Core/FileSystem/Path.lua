local path = { }

path.sep = "\\"

local function at(s,i)
    return string.sub(s,i,i)
end

function path.combine(path1, path2, ...)
    if select('#',...) > 0 then
        local p = path.combine(p1,p2)
        local args = {...}
        for i = 1, #args do
            p = path.combine(p, args[i])
        end
        return p
    end

    local endc = at(p1, #p1)
    if endc ~= path.sep and endc ~= other_sep and endc ~= "" then
        p1 = p1..path.sep
    end

    return p1..p2
end