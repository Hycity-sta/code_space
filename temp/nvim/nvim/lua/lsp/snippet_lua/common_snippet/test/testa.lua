local test = require("./testb")

for key, value in pairs(test) do
    for key_b ,value_b in pairs(value) do
        print(value_b)
    end
end
