CREATE TABLE IF NOT EXISTS ai_os_state (
  id SERIAL PRIMARY KEY,
  project_name TEXT,
  session_id TEXT,
  agent_name TEXT,
  memory_type TEXT,
  context_json JSONB,
  created_at TIMESTAMP DEFAULT NOW()
);

CREATE TABLE IF NOT EXISTS ai_os_events (
  id SERIAL PRIMARY KEY,
  project_name TEXT,
  event_type TEXT,
  payload JSONB,
  created_at TIMESTAMP DEFAULT NOW()
);
