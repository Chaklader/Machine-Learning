import unittest

from agentperformance import TrainEvalPerformance
from simulator import run_with_params, initialize_simulator_environment
from strategies import explorer, exploiter


class TestAgentMethods(unittest.TestCase):

    def setUp(self):
        pass

    def tearDown(self):
        pass


class TestHelperMethods(unittest.TestCase):

    def test_six_agentstates_total(self):
        sim, e = initialize_simulator_environment()
        agentstates = list(e.primary_agent.generate_all_agentstates())
        self.assertEqual(len(agentstates), 6)


class TestAgentBehavior(unittest.TestCase):

    def test_explorer_rarely_reaches_destination(self):
        """Random choices lead to destination <30% of the time."""
        params = {'strategy': explorer}
        performances, agent_info = run_with_params(params)
        pt = TrainEvalPerformance(None, performances, agent_info)
        self.assertLess(pt.prop_eval_reached_destination, 0.3)

    def test_boosted_exploiter_usually_reaches_destination(self):
        """Exploiter with boost=1 reaches destination >80% of the time."""
        params = {'strategy': exploiter, 'q_boost': 1.0}
        performances, agent_info = run_with_params(params)
        pt = TrainEvalPerformance(None, performances, agent_info)
        self.assertGreater(pt.prop_eval_reached_destination, 0.8)


