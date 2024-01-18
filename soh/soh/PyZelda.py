import PyZeldaImpl

class Actor:
    def __init__(self, pointer, with_data=True):
        self._pointer = pointer
        if with_data:
            self.data = PyZeldaImpl.GetInstanceData(self._pointer)

    @property
    def pos(self):
        x = PyZeldaImpl.GetActorPosX(self._pointer)
        y = PyZeldaImpl.GetActorPosY(self._pointer)
        z = PyZeldaImpl.GetActorPosZ(self._pointer)
        return [x, y, z]

    @pos.setter
    def pos(self, new_pos):
        PyZeldaImpl.SetActorPos(self._pointer, new_pos[0], new_pos[1], new_pos[2])

    @property
    def scale(self):
        x = PyZeldaImpl.GetActorScaleX(self._pointer)
        y = PyZeldaImpl.GetActorScaleY(self._pointer)
        z = PyZeldaImpl.GetActorScaleZ(self._pointer)
        return [x, y, z]

    @scale.setter
    def scale(self, new_scale):
        PyZeldaImpl.SetActorScale(self._pointer, new_scale[0], new_scale[1], new_scale[2])

    def draw(self, play):
        PyZeldaImpl.DrawTemp(play, self._pointer)

def get_player(play):
    return Actor(PyZeldaImpl.GetPlayer(play), with_data=False)

def actor_function(func):
    def _wrapped_func(actor, play):
        py_actor = Actor(actor)
        func(py_actor, play)
    return _wrapped_func