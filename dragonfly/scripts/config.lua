-- -----------------------------------------------------------
-- Input queues/processors
-- -----------------------------------------------------------
inputs = {
   { tag="eve", uri="tail:///opt/suricata/var/log/suricata/eve.json", script="eve-etl.lua"}
  -- { tag="yaf", uri="file:///opt/yaf/yaf.log", script="yaf-input.lua"}
}

-- -----------------------------------------------------------
-- Analyzer queues/processors
-- -----------------------------------------------------------
analyzers = {
   -- ---------------------------------------------------------
   -- Examples similar to Bro Frameworks 
   -- See https://www.bro.org/sphinx-git/frameworks/index.html
   -- ---------------------------------------------------------
   -- { tag="file", script="example-file.lua" },
   -- { tag="intel", script="example-intel.lua" },
   -- { tag="control", script="example-control.lua" },
   -- { tag="summary", script="example-summary.lua" },   

   -- ---------------------------------------------------------
   -- General examples 
   -- ---------------------------------------------------------
   { tag="tls", script="example-tls.lua" },
   { tag="dns", script="example-dns.lua" },
   { tag="flow", script="example-flow.lua" },
   -- { tag="ja3", script="example-ja3.lua" },

   -- ---------------------------------------------------------
   -- Machine learning examples using redis
   -- ---------------------------------------------------------
   -- { tag="flow", script="example-flow-ml.lua" },
   -- { tag="dns", script="example-dns-ml.lua" },

}

-- -----------------------------------------------------------
-- Output queues/processors
-- -----------------------------------------------------------
outputs = {
    { tag="log", uri="file://dragonfly.log"},
    { tag="tls", uri="file://tls-alerts.log"},
    { tag="dns", uri="file://dns-alerts.log"},
    { tag="flow", uri="file://flow-alerts.log"},
}
