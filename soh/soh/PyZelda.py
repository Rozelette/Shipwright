import PyZeldaImpl
import ctypes

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

# TODO player

class Vec3s:
    def __init__(self, x, y, z):
        self.x = x
        self.y = y
        self.z = z

def get_player(play):
    return Actor(PyZeldaImpl.GetPlayer(play), with_data=False)

def actor_function(func):
    def _wrapped_func(actor, play):
        py_actor = Actor(actor)
        func(py_actor, play)
    return _wrapped_func

class Vec3s(ctypes.Structure):
    _fields_ = [("x", c_short),
                ("y", c_short),
                ("z", c_short)]

# TODO convert pointer to Vec3s

class Vec3s_wrapper:
    def __init__(self, data, x_get, x_set, y_get, y_set, z_get, z_set, all_get, all_set):
        self._x_get = x_get
        self._x_set = x_set
        self._y_get = y_get
        self._y_set = y_set
        self._z_get = z_get
        self._z_set = z_set
        self._all_get = all_get
        self._all_set = all_set
        self._data = data

    @property
    def x(self):
        return x_get(self._data)

    @x.setter
    def x(self, value):
        x_set(self._data, value)

    @property
    def y(self):
        return y_get(self._data)

    @y.setter
    def y(self, value):
        y_set(self._data, value)

    @property
    def z(self):
        return z_get(self._data)

    @z.setter
    def z(self, value):
        z_set(self._data, value)

    @property
    def all(self):
        return all_get(self._data) # TODO from pointer

    @all.setter
    def all(self, value):
        all_set(self._data, value[0], value[1], value[2])

    def __getitem__(self, key):
        if key == 0:
            return self.x
        elif key == 1:
            return self.y
        elif key == 2:
            return self.z

    def __setitem__(self, key, value):
        if key == 0:
            self.x = value
        elif key == 1:
            self.y = value
        elif key == 2:
            self.z = value

    def get(self):
        return Vec3s(self.x, self.y, self.z)

class Actor:
    def __init__(self):
        self._pos = Vec3s_wrapper(self, PyZeldaImpl.GetActorPosX, PyZeldaImpl.SetActorPosX,
                                  PyZeldaImpl.GetActorPosY, PyZeldaImpl.SetActorPosY,
                                  PyZeldaImpl.GetActorPosZ, PyZeldaImpl.SetActorPosZ,
                                  PyZeldaImpl.GetActorPos, PyZeldaImpl.SetActorPos)
        self._scale = Vec3s_wrapper(self, PyZeldaImpl.GetActorScaleX, PyZeldaImpl.SetActorScaleX,
                                    PyZeldaImpl.GetActorScaleY, PyZeldaImpl.SetActorScaleY,
                                    PyZeldaImpl.GetActorScaleZ, PyZeldaImpl.SetActorScaleZ,
                                    PyZeldaImpl.GetActorScale, PyZeldaImpl.SetActorScale)

    @property
    def pos(self):
        return self._pos

    @pos.setter
    def pos(self, value):
        self._pos.all = value

    @property
    def scale(self):
        return self._scale

    @scale.setter
    def scale(self, value):
        self._scale.all = value


actor = Actor()
actor.pos.x = 0
actor.pos[0] = 0
actor.pos = [1, 2, 3]