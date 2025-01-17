/*
 * Copyright (C) 2012,2013 Intel Corporation
 * Copyright (C) 2013-2017 Red Hat, Inc.
 *
 * This program is free software; you can redistribute it and/or
 * modify it under the terms of the GNU General Public License as
 * published by the Free Software Foundation; either version 2 of the
 * License, or (at your option) any later version.
 *
 * This program is distributed in the hope that it will be useful, but
 * WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the GNU
 * General Public License for more details.
 *
 * You should have received a copy of the GNU General Public License
 * along with this program; if not, see <http://www.gnu.org/licenses/>.
 */

#pragma once

#include "wayland/meta-wayland-actor-surface.h"

#define META_TYPE_WAYLAND_SUBSURFACE (meta_wayland_subsurface_get_type ())
G_DECLARE_FINAL_TYPE (MetaWaylandSubsurface,
                      meta_wayland_subsurface,
                      META, WAYLAND_SUBSURFACE,
                      MetaWaylandActorSurface)

typedef enum
{
  META_WAYLAND_SUBSURFACE_PLACEMENT_ABOVE,
  META_WAYLAND_SUBSURFACE_PLACEMENT_BELOW
} MetaWaylandSubsurfacePlacement;

typedef struct
{
  MetaWaylandSubsurfacePlacement placement;
  MetaWaylandSurface *surface;
  MetaWaylandSurface *sibling;
} MetaWaylandSubsurfacePlacementOp;

void meta_wayland_subsurface_union_geometry (MetaWaylandSubsurface *subsurface,
                                             int                    parent_x,
                                             int                    parent_y,
                                             MtkRectangle          *out_geometry);

void meta_wayland_subsurface_destroy_placement_op (MetaWaylandSubsurfacePlacementOp *op);

void meta_wayland_subsurface_drop_placement_ops (MetaWaylandSurfaceState *state,
                                                 MetaWaylandSurface      *surface);

void meta_wayland_subsurface_parent_destroyed (MetaWaylandSurface *surface);

void meta_wayland_subsurfaces_init (MetaWaylandCompositor *compositor);
