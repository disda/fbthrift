#
# Autogenerated by Thrift
#
# DO NOT EDIT UNLESS YOU ARE SURE THAT YOU KNOW WHAT YOU ARE DOING
#  @generated
#

from folly.iobuf import IOBuf as __IOBuf
import thrift.py3.types
import thrift.py3.exceptions
from thrift.py3.types import NOTSET, NOTSETTYPE
from thrift.py3.serializer import Protocol
import typing as _typing

import sys
import itertools


__property__ = property


class Animal(thrift.py3.types.Enum):
    DOG: Animal = ...
    CAT: Animal = ...
    TARANTULA: Animal = ...


class Color(thrift.py3.types.Struct, _typing.Hashable, _typing.Iterable[_typing.Tuple[str, _typing.Any]]):
    def __init__(
        self, *,
        red: _typing.Optional[float]=None,
        green: _typing.Optional[float]=None,
        blue: _typing.Optional[float]=None,
        alpha: _typing.Optional[float]=None
    ) -> None: ...

    def __call__(
        self, *,
        red: _typing.Union[float, NOTSETTYPE, None]=NOTSET,
        green: _typing.Union[float, NOTSETTYPE, None]=NOTSET,
        blue: _typing.Union[float, NOTSETTYPE, None]=NOTSET,
        alpha: _typing.Union[float, NOTSETTYPE, None]=NOTSET
    ) -> Color: ...

    def __reduce__(self) -> _typing.Tuple[_typing.Callable, _typing.Tuple[_typing.Type['Color'], bytes]]: ...
    def __iter__(self) -> _typing.Iterator[_typing.Tuple[str, _typing.Any]]: ...
    def __bool__(self) -> bool: ...
    def __hash__(self) -> int: ...
    def __repr__(self) -> str: ...
    def __lt__(self, other: 'Color') -> bool: ...
    def __gt__(self, other: 'Color') -> bool: ...
    def __le__(self, other: 'Color') -> bool: ...
    def __ge__(self, other: 'Color') -> bool: ...

    @__property__
    def red(self) -> float: ...
    @__property__
    def green(self) -> float: ...
    @__property__
    def blue(self) -> float: ...
    @__property__
    def alpha(self) -> float: ...


class Vehicle(thrift.py3.types.Struct, _typing.Hashable, _typing.Iterable[_typing.Tuple[str, _typing.Any]]):
    def __init__(
        self, *,
        color: _typing.Optional['Color']=None,
        licensePlate: _typing.Optional[str]=None,
        description: _typing.Optional[str]=None,
        name: _typing.Optional[str]=None,
        hasAC: _typing.Optional[bool]=None
    ) -> None: ...

    def __call__(
        self, *,
        color: _typing.Union['Color', NOTSETTYPE, None]=NOTSET,
        licensePlate: _typing.Union[str, NOTSETTYPE, None]=NOTSET,
        description: _typing.Union[str, NOTSETTYPE, None]=NOTSET,
        name: _typing.Union[str, NOTSETTYPE, None]=NOTSET,
        hasAC: _typing.Union[bool, NOTSETTYPE, None]=NOTSET
    ) -> Vehicle: ...

    def __reduce__(self) -> _typing.Tuple[_typing.Callable, _typing.Tuple[_typing.Type['Vehicle'], bytes]]: ...
    def __iter__(self) -> _typing.Iterator[_typing.Tuple[str, _typing.Any]]: ...
    def __bool__(self) -> bool: ...
    def __hash__(self) -> int: ...
    def __repr__(self) -> str: ...
    def __lt__(self, other: 'Vehicle') -> bool: ...
    def __gt__(self, other: 'Vehicle') -> bool: ...
    def __le__(self, other: 'Vehicle') -> bool: ...
    def __ge__(self, other: 'Vehicle') -> bool: ...

    @__property__
    def color(self) -> 'Color': ...
    @__property__
    def licensePlate(self) -> _typing.Optional[str]: ...
    @__property__
    def description(self) -> _typing.Optional[str]: ...
    @__property__
    def name(self) -> _typing.Optional[str]: ...
    @__property__
    def hasAC(self) -> bool: ...


class Person(thrift.py3.types.Struct, _typing.Hashable, _typing.Iterable[_typing.Tuple[str, _typing.Any]]):
    def __init__(
        self, *,
        id: _typing.Optional[int]=None,
        name: _typing.Optional[str]=None,
        age: _typing.Optional[int]=None,
        address: _typing.Optional[str]=None,
        favoriteColor: _typing.Optional['Color']=None,
        friends: _typing.Optional[_typing.AbstractSet[int]]=None,
        bestFriend: _typing.Optional[int]=None,
        petNames: _typing.Optional[_typing.Mapping[Animal, str]]=None,
        afraidOfAnimal: _typing.Optional[Animal]=None,
        vehicles: _typing.Optional[_typing.Sequence['Vehicle']]=None
    ) -> None: ...

    def __call__(
        self, *,
        id: _typing.Union[int, NOTSETTYPE, None]=NOTSET,
        name: _typing.Union[str, NOTSETTYPE, None]=NOTSET,
        age: _typing.Union[int, NOTSETTYPE, None]=NOTSET,
        address: _typing.Union[str, NOTSETTYPE, None]=NOTSET,
        favoriteColor: _typing.Union['Color', NOTSETTYPE, None]=NOTSET,
        friends: _typing.Union[_typing.AbstractSet[int], NOTSETTYPE, None]=NOTSET,
        bestFriend: _typing.Union[int, NOTSETTYPE, None]=NOTSET,
        petNames: _typing.Union[_typing.Mapping[Animal, str], NOTSETTYPE, None]=NOTSET,
        afraidOfAnimal: _typing.Union[Animal, NOTSETTYPE, None]=NOTSET,
        vehicles: _typing.Union[_typing.Sequence['Vehicle'], NOTSETTYPE, None]=NOTSET
    ) -> Person: ...

    def __reduce__(self) -> _typing.Tuple[_typing.Callable, _typing.Tuple[_typing.Type['Person'], bytes]]: ...
    def __iter__(self) -> _typing.Iterator[_typing.Tuple[str, _typing.Any]]: ...
    def __bool__(self) -> bool: ...
    def __hash__(self) -> int: ...
    def __repr__(self) -> str: ...

    @__property__
    def id(self) -> int: ...
    @__property__
    def name(self) -> str: ...
    @__property__
    def age(self) -> _typing.Optional[int]: ...
    @__property__
    def address(self) -> _typing.Optional[str]: ...
    @__property__
    def favoriteColor(self) -> _typing.Optional['Color']: ...
    @__property__
    def friends(self) -> _typing.Optional[_typing.AbstractSet[int]]: ...
    @__property__
    def bestFriend(self) -> _typing.Optional[int]: ...
    @__property__
    def petNames(self) -> _typing.Optional[_typing.Mapping[Animal, str]]: ...
    @__property__
    def afraidOfAnimal(self) -> _typing.Optional[Animal]: ...
    @__property__
    def vehicles(self) -> _typing.Optional[_typing.Sequence['Vehicle']]: ...


class Set__i64(_typing.AbstractSet[int], _typing.Hashable):
    def __init__(self, items: _typing.AbstractSet[int]=None) -> None: ...
    def __repr__(self) -> str: ...
    def __len__(self) -> int: ...
    def __hash__(self) -> int: ...
    def __contains__(self, x: object) -> bool: ...
    def __copy__(self) -> _typing.AbstractSet[int]: ...
    def isdisjoint(self, other: _typing.AbstractSet[int]) -> bool: ...
    def union(self, other: _typing.AbstractSet[int]) -> 'Set__i64': ...
    def intersection(self, other: _typing.AbstractSet[int]) -> 'Set__i64': ...
    def difference(self, other: _typing.AbstractSet[int]) -> 'Set__i64': ...
    def symmetric_difference(self, other: _typing.AbstractSet[int]) -> 'Set__i64': ...
    def issubset(self, other: _typing.AbstractSet[int]) -> bool: ...
    def issuperset(self, other: _typing.AbstractSet[int]) -> bool: ...
    def __iter__(self) -> _typing.Iterator[int]: ...


class Map__Animal_string(_typing.Mapping[Animal, str], _typing.Hashable):
    def __init__(self, items: _typing.Mapping[Animal, str]=None) -> None: ...
    def __repr__(self) -> str: ...
    def __len__(self) -> int: ...
    def __hash__(self) -> int: ...
    def __contains__(self, x: object) -> bool: ...
    def __copy__(self) -> _typing.Mapping[Animal, str]: ...
    def __getitem__(self, key: Animal) -> str: ...
    def __iter__(self) -> _typing.Iterator[Animal]: ...


_List__VehicleT = _typing.TypeVar('_List__VehicleT', bound=_typing.Sequence['Vehicle'])


class List__Vehicle(_typing.Sequence['Vehicle'], _typing.Hashable):
    def __init__(self, items: _typing.Sequence['Vehicle']=None) -> None: ...
    def __repr__(self) -> str: ...
    def __len__(self) -> int: ...
    def __hash__(self) -> int: ...
    def __contains__(self, x: object) -> bool: ...
    def __copy__(self) -> _typing.Sequence['Vehicle']: ...
    @_typing.overload
    def __getitem__(self, i: int) -> 'Vehicle': ...
    @_typing.overload
    def __getitem__(self, s: slice) -> _typing.Sequence['Vehicle']: ...
    def count(self, item: _typing.Any) -> int: ...
    def index(self, item: _typing.Any, start: int = ..., stop: int = ...) -> int: ...
    def __add__(self, other: _typing.Sequence['Vehicle']) -> 'List__Vehicle': ...
    def __radd__(self, other: _List__VehicleT) -> _List__VehicleT: ...
    def __reversed__(self) -> _typing.Iterator['Vehicle']: ...
    def __iter__(self) -> _typing.Iterator['Vehicle']: ...


PersonID = int
