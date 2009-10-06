--- Returns string representation of object obj
-- @return String representation of obj
function dir(obj,level)
    local s,t = '', type(obj)
    
    level = level or '  '

    if (t=='nil') or (t=='boolean') or (t=='number') or (t=='string') then
        s = tostring(obj)
        if t=='string' then
            s = '"' .. s .. '"'
        end
    elseif t=='function' then s='function'
    elseif t=='userdata' then s='userdata'
    elseif t=='thread' then s='thread'
    elseif t=='table' then
        s = '{'
        for k,v in pairs(obj) do
            local k_str = tostring(k)
            if type(k)=='string' then
                k_str = '["' .. k_str .. '"]'
            end
            s = s .. k_str .. ' = ' .. dir(v,level .. level) .. ', '
        end
        s = string.sub(s, 1, -3)
        s = s .. '}'
    end
    
    return s
end

print (dir(Animator))
print "1==="
a= Animator.clock_period_ms()
print (a)

print "2==="
Animator.set_clock_period_ms(14)
a= Animator.clock_period_ms()
print (a)
print "2.5=="
a=Animator_create()
print "3==="

a= Animator.create()
print (a)
